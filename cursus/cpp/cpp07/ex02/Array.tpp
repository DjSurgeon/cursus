#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _elements(new T[other._size]()), _size(other._size) {
    for (unsigned int i = 0; i < _size; ++i) {
        _elements[i] = other._elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        _elements = new T[_size]();
        for (unsigned int i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif
