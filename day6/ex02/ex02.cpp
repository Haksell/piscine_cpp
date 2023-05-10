#include <cstdlib>
#include <iostream>
#include <stdexcept>

class Base {
  public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

static Base *generate() {
    const int n = rand() % 3;
    if (n == 0)
        return new A;
    else if (n == 1)
        return new B;
    else
        return new C;
}

static void identify(Base *p) {
    std::cout << (dynamic_cast<A *>(p) != NULL   ? 'A'
                  : dynamic_cast<B *>(p) != NULL ? 'B'
                                                 : 'C')
              << std::endl;
}

static void identify(Base &p) { identify(&p); }

int main() {
    A a;
    B b;
    C c;

    srand(time(NULL));
    Base *r1 = generate();
    Base *r2 = generate();
    Base *r3 = generate();

    identify(&a);
    identify(&b);
    identify(&c);
    identify(r1);
    identify(r2);
    identify(r3);

    std::cout << std::endl;

    identify(a);
    identify(b);
    identify(c);
    identify(*r1);
    identify(*r2);
    identify(*r3);

    delete r1;
    delete r2;
    delete r3;
}
