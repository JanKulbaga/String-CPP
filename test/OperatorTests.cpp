#include "OperatorTests.h"
#include "../src/String.h"
#include <cassert>

void stringOperatorAssignmentWithStringReference()
{
	String s = "Hello";
	String s1;
	s1 = s;
	assert(s == s1 && s1 == "Hello");
}

void stringOperatorAssignmentWithConstCharPointer()
{
	String s;
	s = "Hello";
	assert(s == "Hello");
}

void stringOperatorAssignmentWithCharacter()
{
	String s;
	s = 'a';
	assert(s == "a");
}

void stringOperatorEquals()
{
	String s = "Hello";
	String s1 = "Hello";
	String s2 = s;
	assert(s == s1);
	assert(s == s2);
}

void stringOperatorDoesntEquals()
{
	String s = "Hello";
	String s1 = "World";
	assert(s != s1);
}

void stringOperatorLessThan()
{
	String s = "a";
	String s1 = "b";
	assert(s < s1);
}

void stringOperatorGreaterThan()
{
	String s = "b";
	String s1 = "a";
	assert(s > s1);
}

void stringOperatorLessThanOrEqualTo()
{
	String s = "a";
	String s1 = "a";
	String s2 = "b";
	assert(s <= s1);
	assert(s <= s2);
}

void stringOperatorGreaterThanOrEqualTo()
{
	String s = "b";
	String s1 = "b";
	String s2 = "a";
	assert(s >= s1);
	assert(s >= s2);
}

void stringOperatorPlus()
{
	String s = "Hello";
	String s1 = " World";
	String s2 = s + s1;
	assert(s2 == "Hello World");
}

void stringOperatorPlusEquals()
{
	String s = "Hello";
	String s1 = " World";
	s += s1;
	assert(s == "Hello World");
}

void stringOperatorMultiply()
{
	String s = "Hello";
	assert((s * 3) == "HelloHelloHello");
	assert((3 * s) == "HelloHelloHello");
}

void stringOperatorMultiplyEquals()
{
	String s = "Hello";
	s *= 3;
	assert(s == "HelloHelloHello");
}

void stringOperatorIndex()
{
	String s = "Hello";
	const String s1 = "Hello";
	assert(s[0] == 'H');
	assert(s1[1] == 'e');
}
