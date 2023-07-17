#include "StaticMethodTests.h"
#include "../src/String.h"
#include <cassert>

void asciiLettersTest()
{
	assert(String::asciiLetters() == "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void asciiLowerCaseTest()
{
	assert(String::asciiLowerCase() == "abcdefghijklmnopqrstuvwxyz");
}

void asciiUpperCaseTest()
{
	assert(String::asciiUpperCase() == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void digitsTest()
{
	assert(String::digits() == "0123456789");
}

void FromNumberTest()
{
	assert(String::FromNumber(42) == "42");
	assert(String::FromNumber(69) == "69");
	assert(String::FromNumber(420) == "420");
}

void hexDigitsTest()
{
	assert(String::hexDigits() == "0123456789abcdefABCDEF");
}

void octDigitsTest()
{
	assert(String::octDigits() == "01234567");
}

void punctuationTest()
{
	assert(String::punctuation() == "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
}
