#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  try {
    RPN rpn;
    rpn.calculate(argv[1]);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
