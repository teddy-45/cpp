#include "Serializer.hpp"

int main() {
    Data data;
    data.value = 4599;
    data.name = "Teddy Data";

    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Original Data Value: " << data.value << ", Name: " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data: " << raw << std::endl;
    data.value++;

    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data Value: " << deserializedData->value << ", Name: " << deserializedData->name << std::endl;

    if (deserializedData == &data) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
