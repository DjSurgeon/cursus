#include <iostream>
#include "Serializer.hpp"

int main() {
    std::cout << "--- Test 1: Normal Serialization ---" << std::endl;
    Data myData;
    myData.id = 42;
    myData.name = "Test Data";
    myData.value = 3.14f;

    std::cout << "Original Data address: " << &myData << std::endl;
    std::cout << "Original Data contents - id: " << myData.id << ", name: " << myData.name << ", value: " << myData.value << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized raw value (uintptr_t): " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;

    if (deserializedPtr == &myData) {
        std::cout << "Success! Pointers match." << std::endl;
    } else {
        std::cout << "Failure! Pointers do not match." << std::endl;
    }

    std::cout << "Deserialized Data contents - id: " << deserializedPtr->id << ", name: " << deserializedPtr->name << ", value: " << deserializedPtr->value << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 2: NULL Pointer ---" << std::endl;
    uintptr_t rawNull = Serializer::serialize(NULL);
    std::cout << "Serialized NULL value: " << rawNull << std::endl;

    Data* deserializedNull = Serializer::deserialize(rawNull);
    std::cout << "Deserialized NULL address: " << deserializedNull << std::endl;

    if (deserializedNull == NULL) {
        std::cout << "Success! NULL handled correctly." << std::endl;
    } else {
        std::cout << "Failure! NULL not handled correctly." << std::endl;
    }

    return 0;
}
