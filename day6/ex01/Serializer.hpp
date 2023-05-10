#pragma once

#include <iostream>
#include <stdint.h>
#include <string>

struct Data {
    int num;
    std::string fact;
};

class Serializer {
  public:
    ~Serializer();

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

  private:
    Serializer();
    Serializer(Serializer const &serializer);
    Serializer &operator=(Serializer const &serializer);
};
