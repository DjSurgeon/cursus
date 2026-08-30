#include <iostream>
#include <string>
#include "iter.hpp"

// normal function for mutable array
void increment(int& n)
{
    n++;
}

// function template for the subject ("instantiated function template")
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

int main(void)
{
    // Test 1: mutable array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    ::iter(intArray, intLen, increment);

    std::cout << "Incremented intArray: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // Test 2: immutable array of strings (Demonstrating Const Correctness)
    const std::string stringArray[] = {"Hello", "42", "World"};
    size_t stringLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Constant stringArray: ";
    ::iter(stringArray, stringLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
