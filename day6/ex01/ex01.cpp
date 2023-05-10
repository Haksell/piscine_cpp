#include "Serializer.hpp"

int main() {
    Data *data1 = new Data;
    data1->num = 42;
    data1->fact = "Pierre qui roule n'amasse pas mousse.";
    Data *data2 = Serializer::deserialize(Serializer::serialize(data1));
    std::cout << data2->num << std::endl;
    std::cout << data2->fact << std::endl;
    delete data1;
}
