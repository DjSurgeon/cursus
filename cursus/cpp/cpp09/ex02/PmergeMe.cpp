#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
        this->_timeVec = rhs._timeVec;
        this->_timeDeq = rhs._timeDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::ErrorException::what() const throw() {
    return "Error";
}

void PmergeMe::_printSequence(const std::string& prefix, const std::vector<int>& seq) const {
    std::cout << prefix;
    int count = 0;
    std::vector<int>::const_iterator it;
    for (it = seq.begin(); it != seq.end(); ++it) {
        if (count > 0) std::cout << " ";

        if (count == 7 && seq.size() > 7) {
            std::cout << "[...]";
            break;
        }

        std::cout << *it;
        count++;
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::_generateJacobsthal(int size) const {
    std::vector<int> jacob;
    if (size <= 0) return jacob;
    
    jacob.push_back(1);
    if (size == 1) return jacob;
    jacob.push_back(3);
    
    while (jacob.back() < size) {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

void PmergeMe::_sortVector(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector< std::pair<int, int> > pairs;
    std::vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it += 2) {
        int first = *it;
        int second = *(it + 1);
        if (first < second) {
            std::swap(first, second);
        }
        pairs.push_back(std::make_pair(first, second));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    _sortVector(mainChain);

    std::vector<int> pend;
    std::vector<int>::iterator mainIt;
    for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt) {
        std::vector< std::pair<int, int> >::iterator it;
        for (it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->first == *mainIt) {
                pend.push_back(it->second);
                pairs.erase(it);
                break;
            }
        }
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    std::vector<int> jacobSeq = _generateJacobsthal(pend.size());
    int last_inserted_idx = 1;

    std::vector<int>::iterator jacobIt = jacobSeq.begin();
    if (jacobIt != jacobSeq.end()) ++jacobIt;

    for (; jacobIt != jacobSeq.end(); ++jacobIt) {
        int current_jacob = *jacobIt;
        if (current_jacob > (int)pend.size()) {
            current_jacob = pend.size();
        }

        for (int j = current_jacob; j > last_inserted_idx; --j) {
            int itemToInsert = pend[j - 1];
            
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), itemToInsert);
            mainChain.insert(pos, itemToInsert);
        }
        last_inserted_idx = current_jacob;
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;

}

void PmergeMe::_sortDeque(std::deque<int>& arr) {
    if (arr.size() < 2) return;

    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque< std::pair<int, int> > pairs;
    for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); it += 2) {
        int first = *it;
        int second = *(it + 1);
        if (first < second) {
            std::swap(first, second);
        }
        pairs.push_back(std::make_pair(first, second));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    _sortDeque(mainChain);

    std::deque<int> pend;
    std::deque<int>::iterator mainIt;
    for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt) {
        for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->first == *mainIt) {
                pend.push_back(it->second);
                pairs.erase(it);
                break;
            }
        }
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    std::vector<int> jacobSeq = _generateJacobsthal(pend.size());
    int last_inserted_idx = 1;

    std::vector<int>::iterator jacobIt = jacobSeq.begin();
    if (jacobIt != jacobSeq.end()) ++jacobIt;

    for (; jacobIt != jacobSeq.end(); ++jacobIt) {
        int current_jacob = *jacobIt;
        if (current_jacob > (int)pend.size()) {
            current_jacob = pend.size();
        }

        for (int j = current_jacob; j > last_inserted_idx; --j) {
            int itemToInsert = pend[j - 1];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), itemToInsert);
            mainChain.insert(pos, itemToInsert);
        }
        last_inserted_idx = current_jacob;
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sort(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) throw ErrorException();
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j]) && arg[j] != '+') {
                throw ErrorException();
            }
        }

        long long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647) throw ErrorException();

        int final_val = static_cast<int>(val);

        if (std::find(_vec.begin(), _vec.end(), final_val) != _vec.end()) {
            throw ErrorException();
        }

        _vec.push_back(final_val);
        _deq.push_back(final_val);
    }

    _printSequence("Before: ", _vec);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    _sortVector(_vec);
    gettimeofday(&end, NULL);
    _timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    _sortDeque(_deq);
    gettimeofday(&end, NULL);
    _timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    _printSequence("After:  ", _vec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << _timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}
