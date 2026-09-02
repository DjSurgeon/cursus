#include "BitcoinExchange.hpp"

// -----------------------------------------------------------------------------
// Constructor and Destructor
// -----------------------------------------------------------------------------

BitcoinExchange::BitcoinExchange() { _loadDatabase("data.csv"); }

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
  _loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { *this = src; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  if (this != &rhs) {
    this->_database = rhs._database;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// -----------------------------------------------------------------------------
// Exceptions
// -----------------------------------------------------------------------------

const char* BitcoinExchange::FileOpenException::what() const throw() {
  return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidDatabaseException::what() const throw() {
  return "Fatal Error: Invalid database format or corrupted data in CSV.";
}

// -----------------------------------------------------------------------------
// Private Helpers for Parsing and Validation
// -----------------------------------------------------------------------------

std::string BitcoinExchange::_trim(const std::string& str) const {
  size_t first = str.find_first_not_of(" \t\n\r\f\v");
  if (first == std::string::npos) return "";
  size_t last = str.find_last_not_of(" \t\n\r\f\v");
  return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
  if (date.length() != 10) return false;
  if (date[4] != '-' || date[7] != '-') return false;

  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 7) continue;
    if (!isdigit(date[i])) return false;
  }

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;

  // Validation of days in month and leap years
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    daysInMonth[2] = 29;
  }

  if (day > daysInMonth[month]) return false;

  return true;
}

bool BitcoinExchange::_isValidExchange(const std::string& rateStr) const {
  if (rateStr.empty()) return false;
  char* endptr;
  double val = std::strtod(rateStr.c_str(), &endptr);
  if (*endptr != '\0') return false;
  if (val < 0.0) return false;
  return true;
}

bool BitcoinExchange::_isValidInputValue(const std::string& valueStr) const {
  if (valueStr.empty()) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }
  char* endptr;
  double val = std::strtod(valueStr.c_str(), &endptr);
  if (*endptr != '\0') {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }
  if (val < 0.0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }
  if (val > 1000.0) {
    std::cerr << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}

// -----------------------------------------------------------------------------
// Main logic
// -----------------------------------------------------------------------------

void BitcoinExchange::_loadDatabase(const std::string& dbPath) {
  std::ifstream file(dbPath.c_str());
  if (!file.is_open()) {
    throw FileOpenException();
  }

  std::string line;
  // Skip header
  std::getline(file, line);

  while (std::getline(file, line)) {
    if (line.empty()) continue;
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos) {
      throw InvalidDatabaseException();
    }

    std::string dateStr = _trim(line.substr(0, commaPos));
    std::string rateStr = _trim(line.substr(commaPos + 1));

    if (!_isValidDate(dateStr) || !_isValidExchange(rateStr)) {
      throw InvalidDatabaseException();
    }

    float rate = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
    _database[dateStr] = rate;
  }
  file.close();
}

void BitcoinExchange::processInput(const std::string& inputPath) const {
  std::ifstream file(inputPath.c_str());
  if (!file.is_open()) {
    throw FileOpenException();
  }

  std::string line;
  std::getline(file, line);  // Skip header

  while (std::getline(file, line)) {
    if (line.empty()) continue;

    size_t sepPos = line.find('|');
    if (sepPos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string dateStr = _trim(line.substr(0, sepPos));
    std::string valueStr = _trim(line.substr(sepPos + 1));

    if (!_isValidDate(dateStr)) {
      std::cerr << "Error: bad input => " << (dateStr.empty() ? line : dateStr)
                << std::endl;
      continue;
    }

    if (!_isValidInputValue(valueStr)) {
      continue;
    }

    float value = static_cast<float>(std::strtod(valueStr.c_str(), NULL));

    /*
     * =========================================================================================
     * `std::map::lower_bound` IN C++98
     * =========================================================================================
     * The `std::map` container is internally implemented as a self-balancing
     * binary search tree (typically a Red-Black tree). This means that the keys
     * are kept strictly ordered lexicographically (which fits perfectly with
     * dates in YYYY-MM-DD format).
     *
     * The `lower_bound(key)` method searches algorithmically in O(log N) time
     * for the first iterator that points to an element whose key is NOT
     * strictly less than `key`. That is, the found element will be `>= key`.
     *
     * To comply with the subject rule: "If the date does not exist, use the
     * nearest previous date", the logical flow using iterators is as follows:
     *
     * 1. We perform the search: `it = _database.lower_bound(dateStr)`.
     * 2. If `it` points exactly to `dateStr`, we use that value (the exact date
     * was found).
     * 3. If `it` is NOT the exact date, it means it points to the first
     * immediately **POSTERIOR** date a `dateStr` in the database (or `.end()`
     * if `dateStr` is greater than all).
     * 4. To get the "nearest previous date", we simply move the iterator back
     * one position: `--it`.
     * 5. **CRITICAL edge case**: If `it == _database.begin()` and it does not
     * match the exact date, then `dateStr` is older than any record in our CSV,
     * so it is logically impossible to offer a valid historical valuation.
     * =========================================================================================
     */

    std::map<std::string, float>::const_iterator it =
        _database.lower_bound(dateStr);

    if (it == _database.end() || it->first != dateStr) {
      if (it == _database.begin()) {
        std::cerr << "Error: Date " << dateStr
                  << " is older than any record in the database." << std::endl;
        continue;
      }
      --it;  // Move back to the strictly smaller valid iterator
    }

    float exchangeRate = it->second;
    std::cout << dateStr << " => " << value << " = " << (value * exchangeRate)
              << std::endl;
  }
  file.close();
}
