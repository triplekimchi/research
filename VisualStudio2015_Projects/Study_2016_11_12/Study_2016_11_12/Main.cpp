#include <iostream>
#include <bitset>

namespace example
{
	void print_example();

	void print_example2()
	{
		std::cout << "I'm example2" << std::endl;
	}
}

typedef enum example2
{
	ex1,
	ex2 = 3,
	ex3
}Ex;

enum class Example3 : unsigned int
{
	ex1,
	ex2 = 4,
	ex3
};

int main(int argc,char* argv[])
{
	example::print_example();
	example::print_example2();

	int a = 1;
	int b = 2;
	// a = 00000001 << 2
	// a = 00000100
	a = a << 2;

	// b = 00000010 >> 1
	// b = 00000001
	b = b >> 1;

	std::bitset<8> c(a);
	std::bitset<8> d(b);
	std::cout << "a = " << c << std::endl;
	std::cout << "b = " << d << std::endl;

	int e = 3;
	// e = 00000011 ^ 00000100
	// e = 00000111
	// e = 7
	e = e ^ a;
	std::bitset<8> f(e);
	std::cout << "bit e = " << f << std::endl;
	std::cout << "int e = " << e << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex2 = " << ex2 << std::endl;
	std::cout << "ex3 = " << ex3 << std::endl;
	
	std::cout << "k = " << example2::ex1 << std::endl;
	if(!(Ex::ex1 == ex2))
		if(!(ex2 == ex3))
			std::cout << "Enum can be compared!" << std::endl;

	/*
		if(Ex::ex1 == Example3::ex1) --> X
		if(Example3::ex1 == Ex::ex1) --> X
		std::cout << "example3 ex1 = " << Example3::ex1 << std::endl; --> X
	
	*/

	// how to use enum class
	Example3 enum_ex = static_cast<Example3>(4);

	switch(enum_ex)
	{
		case Example3::ex1:
			std::cout << "example3 ex1" << std::endl;
			break;
		case Example3::ex2:
			std::cout << "example3 ex2" << std::endl;
			break;
		case Example3::ex3:
			std::cout << "example3 ex3" << std::endl;
			break;
		default:
			std::cout << "default break; " << std::endl;
			break;
	}
	return 0;
}

void example::print_example()
{
	std::cout << "I'm example" << std::endl;
}
