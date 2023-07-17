#include "../src/String.h"
#include "Test.h"
#include <ostream>

int main()
{
	MethodTests();
	IteratorTests();
	StaticMethodTests();
	OperatorTests();

	std::cout << "All tests passed!\n";
	return 0;
}
