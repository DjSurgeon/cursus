#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
    (void)a;
    (void)b;
}

template <typename T>
const T& min(const T& a, const T& b) {
    (void)b;
    return a;
}

template <typename T>
const T& max(const T& a, const T& b) {
    (void)b;
    return a;
}

#endif
