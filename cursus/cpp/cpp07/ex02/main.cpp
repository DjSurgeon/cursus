#include <iostream>
#include "Array.hpp"

int main(void) {
    std::cout << "--- TEST 1: Default Constructor ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n--- TEST 2: Parameterized Constructor & Initialization ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl; // Should be 0
    }

    std::cout << "\n--- TEST 3: Mutability via operator[] ---" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n--- TEST 4: Deep Copy (Copy Constructor) ---" << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 999;
    std::cout << "copyArray[0] (Modified): " << copyArray[0] << std::endl;
    std::cout << "intArray[0] (Original, should remain 0): " << intArray[0] << std::endl;

    std::cout << "\n--- TEST 5: Deep Copy (Assignment Operator) ---" << std::endl;
    Array<int> assignedArray = intArray;
    assignedArray[1] = 888;
    std::cout << "assignedArray[1] (Modified): " << assignedArray[1] << std::endl;
    std::cout << "intArray[1] (Original, should remain 10): " << intArray[1] << std::endl;

    std::cout << "\n--- TEST 6: Out of Bounds Exception Handling ---" << std::endl;
    try {
        std::cout << "Attempting to access index 5 (size is 5)..." << std::endl;
        intArray[5] = 100;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access index -1..." << std::endl;
        intArray[-1] = 100;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}
