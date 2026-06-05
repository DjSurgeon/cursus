#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { *this = other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    // Lógica pendiente
    (void)ptr;
    return 0; 
}

Data* Serializer::deserialize(uintptr_t raw) {
    // Lógica pendiente
    (void)raw;
    return NULL; 
}
