#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

class Base {
public:
	virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

static Base* generate() {
	const int n = rand() % 3;
	if (n == 0)
		return new A;
	else if (n == 1)
		return new B;
	else
		return new C;
}

static void identify(Base* p) {
	char type = dynamic_cast<A*>(p) ? 'A' : dynamic_cast<B*>(p) ? 'B' : 'C';
	std::cout << type << std::endl;
}

static void identify(Base& p) {
	Base q;
	try {
		q = dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (const std::exception& e) {
		try {
			q = dynamic_cast<B&>(p);
			std::cout << "B\n";
		} catch (const std::exception& e) {
			std::cout << "C\n";
		}
	}
}

int main() {
	A a;
	B b;
	C c;

	std::srand(std::time(NULL));
	Base* r1 = generate();
	Base* r2 = generate();
	Base* r3 = generate();

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
