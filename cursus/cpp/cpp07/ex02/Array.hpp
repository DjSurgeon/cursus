#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index is out of bounds";
        }
    };

    // Orthodox Canonical Form
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    // Access operators
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // Member function
    unsigned int size() const;
};

#include "Array.tpp"

#endif
