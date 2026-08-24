#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
	Base *obj;
	int obj_selector = std::rand() % 3;
	switch(obj_selector)
	{
		case(0):
			obj = new A();
			break;
		case(1):
			obj = new B();
			break;
		case(2):
			obj = new C();
			break;
		default:
			obj = NULL;
	}
	return obj;
}

void identify(Base* p)
{
	A *Aobj = dynamic_cast<A *>(p);
	B *Bobj = dynamic_cast<B *>(p);
	C *Cobj = dynamic_cast<C *>(p);
	if (Aobj)
		std::cout << "A" << std::endl;
	else if (Bobj)
		std::cout << "B" << std::endl;
	else if (Cobj)
		std::cout << "C" << std::endl;
	else
		std::cout << "INVALID" << std::endl;
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e) {
		(void)e;
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e) {
		(void)e;
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e) {
		(void)e;
	}
}

int main(void)
{
	std::srand(time(NULL));
	Base *obj1 = generate();
	Base *obj2 = generate();
	Base *obj3 = NULL;
	identify(obj1);
	identify(*obj2);
	identify(obj3);
	delete obj1;
	delete obj2;
	return 0;
}