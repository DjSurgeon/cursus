#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.sort(argc, argv);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
