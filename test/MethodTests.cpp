#include "MethodTests.h"
#include "../src/String.h"
#include <cstring>
#include <cassert>

void backTest()
{
	String s = "Hello World";
	assert(s.back() == 'd');
	assert(s.back() != 'l');
}

void charAtTest()
{
	String s = "Hello";
	const String s1 = "Hello";
	assert(s.charAt(0) == 'H');
	assert(s1.charAt(1) == 'e');
}

void clearTest()
{
	String s = "Hello World";
	s.clear();
	assert(s.length() == 0);
	assert(s.c_str() == nullptr);
}

void c_strTest()
{
	String s = "Hello World";
	String s1;
	assert(strcmp(s.c_str(), "Hello World") == 0);
	assert(s1.c_str() == nullptr);
}

void endsWithTest()
{
	String s = "Hello World";
	assert(s.endsWith("d") == true);
	assert(s.endsWith("World") == true);
	assert(s.endsWith("l") == false);
}

void findTest()
{
	String s = "Hello World";
	assert(s.find("l") == 2);
	assert(s.find("H") == 0);
	assert(s.find("W") == 6);
	assert(s.find("a") == -1);
	assert(s.find("") == -1);
}

void frontTest()
{
	String s = "Hello World";
	assert(s.front() == 'H');
	assert(s.front() != 'e');
}

void isAlphaTest()
{
	String s = "Hello";
	String s1 = "Hello World";
	String s2 = "0123456789";
	assert(s.isAlpha() == true);
	assert(s1.isAlpha() == false);
	assert(s2.isAlpha() == false);
}

void isDigitTest()
{
	String s = "Hello World";
	String s1 = "0123456789";
	assert(s.isDigit() == false);
	assert(s1.isDigit() == true);
}

void isSpaceTest()
{
	String s = "Hello ";
	String s1 = " ";
	assert(s.isSpace() == false);
	assert(s1.isSpace() == true);
}

void isEmptyTest()
{
	String s;
	String s1 = "Hello World";
	String s2 = "Hello";
	s1.clear();
	assert(s.isEmpty() == true);
	assert(s1.isEmpty() == true);
	assert(s2.isEmpty() == false);
}

void lengthTest()
{
	String s = "Hello World";
	String s1 = "";
	String s2;
	assert(s.length() == 11);
	assert(s1.length() == 0);
	assert(s1.length() == 0);
}

void lowerTest()
{
	String s = "HeLlO WoRlD";
	String s1 = "hello world";
	String s2 = "";
	assert(s.lower() == "hello world");
	assert(s1.lower() == "hello world");
	assert(s2.lower() == "");
}

void trimTest()
{
	String s = "   Hello World   ";
	String s1 = "Hello World   ";
	String s2 = "   Hello World";
	assert(s.trim() == "Hello World");
	assert(s1.trim() == "Hello World");
	assert(s2.trim() == "Hello World");
}

void trimEndTest()
{
	String s = "   Hello World   ";
	String s1 = "Hello World   ";
	String s2 = "   Hello World";
	assert(s.trimEnd() == "   Hello World");
	assert(s1.trimEnd() == "Hello World");
	assert(s2.trimEnd() == "   Hello World");
}

void trimStartTest()
{
	String s = "   Hello World   ";
	String s1 = "Hello World   ";
	String s2 = "   Hello World";
	assert(s.trimStart() == "Hello World   ");
	assert(s1.trimStart() == "Hello World   ");
	assert(s2.trimStart() == "Hello World");
}

void startsWithTest()
{
	String s = "Hello World";
	assert(s.startsWith("H") == true);
	assert(s.startsWith("Hello") == true);
	assert(s.startsWith("W") == false);
}

void substringTest()
{
	String s = "Hello World";
	assert(s.substring(1, 3) == "ell");
	assert(s.substring(3, 8) == "lo Wor");
}

void upperTest()
{
	String s = "hElLo wOrLd";
	String s1 = "HELLO WORLD";
	String s2 = "";
	assert(s.upper() == "HELLO WORLD");
	assert(s1.upper() == "HELLO WORLD");
	assert(s2.upper() == "");
}

void zfillTest()
{
	String s = "Hello";
	assert(s.zfill(10) == "00000Hello");
	assert(s.zfill(5) == "Hello");
	assert(s.zfill(4) == "Hello");
}