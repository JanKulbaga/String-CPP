#include "IteratorTests.h"
#include "../src/String.h"
#include <cassert>

void beginTest()
{
	String s = "Hello World";
	assert(*(s.begin()) == 'H');
}

void endTest()
{
	String s = "Hello World";
	assert(s.end() == (s.begin() + s.length()));
}

void cbeginTest()
{
	const String s = "Hello World";
	assert(*(s.cbegin()) == 'H');
}

void cendTest()
{
	const String s = "Hello World";
	assert(s.cend() == (s.cbegin() + s.length()));
}

void rbeginTest()
{
	String s = "Hello World";
	assert(*(s.rbegin()) == 'd');
}

void rendTest()
{
	String s = "Hello World";
	assert(*(s.rend()) == *(s.c_str() - 1));
}

void crbeginTest()
{
	const String s = "Hello World";
	assert(*(s.crbegin()) == 'd');
}

void crendTest()
{
	const String s = "Hello World";
	assert(*(s.crend()) == *(s.c_str() - 1));
}

void iteratorOperatorDereferenceTest()
{
	String s = "Hello World";
	assert(*(s.begin()) == 'H');
}

void iteratorOperatorEqualsTest()
{
	String s = "Hello World";
	String::Iterator it = s.begin();
	String::Iterator it1 = s.begin();
	assert(it == it1);
}

void iteratorOperatorDoesntEqualsTest()
{
	String s = "Hello World";
	String::Iterator it = s.begin();
	String::Iterator it1 = s.end();
	assert(it != it1);
}

void reverseIteratorOperatorDereferenceTest()
{
	String s = "Hello World";
	assert(*(s.rbegin()) == 'd');
}

void reverseIteratorOperatorEqualsTest()
{
	String s = "Hello World";
	String::ReverseIterator it = s.rbegin();
	String::ReverseIterator it1 = s.rbegin();
	assert(it == it1);
}

void reverseiIteratorOperatorDoesntEqualsTest()
{
	String s = "Hello World";
	String::ReverseIterator it = s.rbegin();
	String::ReverseIterator it1 = s.rend();
	assert(it != it1);
}
