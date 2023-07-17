#include "OperatorTests.h"
#include "../src/String.h"
#include <cassert>

void stringOperatorAssignmentWithStringReferenceTest()
{
	String s = "Hello";
	String s1;
	s1 = s;
	assert(s == s1 && s1 == "Hello");
}

void stringOperatorAssignmentWithConstCharPointerTest()
{
	String s;
	s = "Hello";
	assert(s == "Hello");
}

void stringOperatorAssignmentWithCharacterTest()
{
	String s;
	s = 'a';
	assert(s == "a");
}

void stringOperatorEqualsTest()
{
	String s = "Hello";
	String s1 = "Hello";
	String s2 = s;
	assert(s == s1);
	assert(s == s2);
}

void stringOperatorDoesntEqualsTest()
{
	String s = "Hello";
	String s1 = "World";
	assert(s != s1);
}

void stringOperatorLessThanTest()
{
	String s = "a";
	String s1 = "b";
	assert(s < s1);
}

void stringOperatorGreaterThanTest()
{
	String s = "b";
	String s1 = "a";
	assert(s > s1);
}

void stringOperatorLessThanOrEqualToTest()
{
	String s = "a";
	String s1 = "a";
	String s2 = "b";
	assert(s <= s1);
	assert(s <= s2);
}

void stringOperatorGreaterThanOrEqualToTest()
{
	String s = "b";
	String s1 = "b";
	String s2 = "a";
	assert(s >= s1);
	assert(s >= s2);
}

void stringOperatorPlusTest()
{
	String s = "Hello";
	String s1 = " World";
	String s2 = s + s1;
	assert(s2 == "Hello World");
}

void stringOperatorPlusEqualsTest()
{
	String s = "Hello";
	String s1 = " World";
	s += s1;
	assert(s == "Hello World");
}

void stringOperatorMultiplyTest()
{
	String s = "Hello";
	assert((s * 3) == "HelloHelloHello");
	assert((3 * s) == "HelloHelloHello");
}

void stringOperatorMultiplyEqualsTest()
{
	String s = "Hello";
	s *= 3;
	assert(s == "HelloHelloHello");
}

void stringOperatorIndexTest()
{
	String s = "Hello";
	const String s1 = "Hello";
	assert(s[0] == 'H');
	assert(s1[1] == 'e');
}
