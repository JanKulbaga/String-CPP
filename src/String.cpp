#include "String.h"

String::String(char c)
	: m_Length(1), m_Data(new char[2])
{
	m_Data[0] = c;
	m_Data[1] = '\0';
}

String::String(const char* const str)
{
	if (str == nullptr)
		throw std::invalid_argument("String::String(const char* const str): str is nullptr");
	m_Length = strlen(str);
	m_Data = new char[m_Length + 1];
	memcpy(m_Data, str, m_Length);
	m_Data[m_Length] = '\0';
}

String::String(const String& other)
	: m_Length(other.m_Length)
{
	if (other.m_Data == nullptr)
		throw std::invalid_argument("String::String(const String& other): other is nullptr");
	delete[] m_Data;
	m_Data = new char[m_Length + 1];
	strcpy_s(m_Data, m_Length + 1, other.m_Data);
}

String::~String()
{
	delete[] m_Data;
	m_Data = nullptr;
}

String& String::operator=(const String& other)
{
	if (other.m_Data == nullptr)
		throw std::invalid_argument("String& String::operator=(const String& other): other is nullptr");
	if (this == &other)
		return *this;
	delete[] m_Data;
	m_Length = other.m_Length;
	m_Data = new char[m_Length + 1];
	strcpy_s(m_Data, m_Length + 1, other.m_Data);
	return *this;
}

String& String::operator=(const char* const str)
{
	if (str == nullptr)
		throw std::invalid_argument("String& String::operator=(const char* const str): str is nullptr");
	if (this->m_Data != nullptr && strcmp(this->m_Data, str) == 0)
		return *this;
	delete[] m_Data;
	m_Length = strlen(str);
	m_Data = new char[m_Length + 1];
	memcpy(m_Data, str, m_Length);
	m_Data[m_Length] = '\0';
	return *this;
}

String& String::operator=(char c)
{
	delete[] m_Data;
	m_Length = 1;
	m_Data = new char[m_Length + 1];
	m_Data[0] = c;
	m_Data[1] = '\0';
	return *this;
}

String& String::operator+=(const String& other)
{
	size_t newLength = m_Length + other.m_Length;
	char* data = new char[newLength + 1];
	strcpy_s(data, m_Length + 1, m_Data);
	strcat_s(data, newLength + 1, other.m_Data);
	m_Data = data;
	m_Length = newLength;
	return *this;
}

String& String::operator*=(size_t num)
{
	size_t length = m_Length * num;
	char* data = new char[length + 1];
	for (size_t i = 0; i < length; ++i)
		data[i] = m_Data[i % m_Length];
	data[length] = '\0';
	m_Data = data;
	m_Length = length;
	return *this;
}

char& String::operator[](size_t index)
{
	if (index >= m_Length)
		throw std::out_of_range("char& String::operator[](size_t index): index out of range");
	return m_Data[index];
}

char& String::operator[](size_t index) const
{
	if (index >= m_Length)
		throw std::out_of_range("char& String::operator[](size_t index) const: index out of range");
	return m_Data[index];
}

String::Iterator String::begin()
{
	return Iterator(m_Data);
}

String::Iterator String::end()
{
	return Iterator(m_Data + m_Length);
}

String::Iterator String::cbegin() const
{
	return Iterator(m_Data);
}

String::Iterator String::cend() const
{
	return Iterator(m_Data + m_Length);
}

String::ReverseIterator String::rbegin()
{
	return ReverseIterator(m_Data + m_Length - 1);
}

String::ReverseIterator String::rend()
{
	return ReverseIterator(m_Data - 1);
}

String::ReverseIterator String::crbegin() const
{
	return ReverseIterator(m_Data + m_Length - 1);
}

String::ReverseIterator String::crend() const
{
	return ReverseIterator(m_Data - 1);
}

char& String::back() const
{
	return m_Data[m_Length - 1];
}

void String::clear()
{
	delete[] m_Data;
	m_Data = nullptr;
	m_Length = 0;
}

const char* String::c_str() const
{
	return m_Data;
}

bool String::endsWith(const char* const str) const
{
	if (str == nullptr || *str == '\0')
		return false;
	size_t otherLength = strlen(str);
	if (m_Length < otherLength)
		return false;
	size_t startIdx = m_Length - otherLength;
	for (size_t i = 0; i < otherLength; ++i)
	{
		if (m_Data[startIdx + i] != str[i])
			return false;
	}
	return true;
}

int64_t String::find(const char* const str) const
{
	if (str == nullptr || *str == '\0')
		return -1;
	size_t otherLength = strlen(str);
	if (otherLength > m_Length)
		return -1;
	for (size_t i = 0; i <= m_Length - otherLength; ++i)
	{
		bool match = true;
		for (size_t j = 0; j < otherLength; ++j)
		{
			if (m_Data[i + j] != str[j])
			{
				match = false;
				break;
			}
		}
		if (match)
			return i;
	}

	return -1;
}

char& String::front() const
{
	return m_Data[0];
}

bool String::isAlpha() const
{
	if (m_Length == 0)
		return false;

	for (size_t i = 0; i < m_Length; ++i)
	{
		if (!std::isalpha(m_Data[i]))
			return false;
	}
	return true;
}

bool String::isDigit() const
{
	if (m_Length == 0)
		return false;

	for (size_t i = 0; i < m_Length; ++i)
	{
		if (!std::isdigit(m_Data[i]))
			return false;
	}
	return true;
}

bool String::isSpace() const
{
	if (m_Length == 0)
		return false;

	for (size_t i = 0; i < m_Length; ++i)
	{
		if (!std::isspace(m_Data[i]))
			return false;
	}
	return true;
}

bool String::isEmpty() const
{
	return m_Length == 0;
}

size_t String::length() const
{
	return m_Length;
}

String String::lower() const
{
	String result(*this);
	for (size_t i = 0; i < result.length(); ++i)
	{
		char& c = result.m_Data[i];
		c = std::tolower(c);
	}
	return result;
}

String String::trim() const
{
	if (m_Length == 0)
		return String("");

	size_t start = 0;
	size_t end = m_Length - 1;

	while (start <= end && std::isspace(m_Data[start]))
		start++;
	while (end >= start && std::isspace(m_Data[end]))
		end--;

	size_t length = end - start + 1;
	char* data = new char[length + 1];
	memcpy(data, m_Data + start, length);
	data[length] = '\0';
	return String(data);
}

String String::trimEnd() const
{
	if (m_Length == 0)
		return String("");

	size_t end = m_Length - 1;
	while (end >= 0 && std::isspace(m_Data[end]))
		end--;

	size_t length = end + 1;
	char* data = new char[length + 1];
	memcpy(data, m_Data, length);
	data[length] = '\0';

	return String(data);
}

String String::trimStart() const
{
	if (m_Length == 0)
		return String("");

	size_t start = 0;
	while (start < m_Length && std::isspace(m_Data[start]))
		start++;

	size_t length = m_Length - start;
	char* data = new char[length + 1];
	memcpy(data, m_Data + start, length);
	data[length] = '\0';

	return String(data);
}

bool String::startsWith(const char* const str) const
{
	if (str == nullptr || *str == '\0')
		return false;
	size_t otherLength = strlen(str);
	if (m_Length < otherLength)
		return false;
	for (size_t i = 0; i < otherLength; ++i)
	{
		if (m_Data[i] != str[i])
			return false;
	}
	return true;
}

String String::substring(size_t start, size_t end) const
{
	if (start > m_Length || start > end)
		return String(m_Data);
	size_t length = end - start + 1;
	char* data = new char[length + 1];
	memcpy(data, m_Data + start, length);
	data[length] = '\0';
	return String(data);
}

String String::upper() const
{
	String result(*this);
	for (size_t i = 0; i < result.length(); ++i)
	{
		char& c = result.m_Data[i];
		c = std::toupper(c);
	}
	return result;
}

String String::zfill(size_t num) const
{
	if (num <= m_Length)
		return String(m_Data);
	String result = String("0") * (num - m_Length);
	result += m_Data;
	return result;
}

String String::asciiLetters()
{
	return String("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

String String::asciiLowerCase()
{
	return String("abcdefghijklmnopqrstuvwxyz");
}

String String::asciiUpperCase()
{
	return String("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

String String::digits()
{
	return String("0123456789");
}

String String::FromNumber(size_t num)
{
	size_t digits = 0;
	size_t temp = num;
	do
	{
		++digits;
		temp /= 10;
	} while (temp != 0);

	char* data = new char[digits + 1];

	for (size_t i = digits; i > 0; --i)
	{
		data[i - 1] = (num % 10) + '0';
		num /= 10;
	}
	data[digits] = '\0';
	return String(data);
}

String String::hexDigits()
{
	return String("0123456789abcdefABCDEF");
}

String String::octDigits()
{
	return String("01234567");
}

String String::punctuation()
{
	return String("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
}

bool operator==(const String& s1, const String& s2)
{
	if (s1.m_Length != s2.m_Length)
		return false;
	if (s1.m_Data == nullptr && s2.m_Data == nullptr)
		return true;
	if (s1.m_Data == nullptr || s2.m_Data == nullptr)
		return false;
	return strcmp(s1.m_Data, s2.m_Data) == 0;
}

bool operator!=(const String& s1, const String& s2)
{
	return !(s1 == s2);
}

bool operator<(const String& s1, const String& s2)
{
	if (s1.m_Data == nullptr || s2.m_Data == nullptr)
		return false;
	return strcmp(s1.m_Data, s2.m_Data) < 0;
}

bool operator>(const String& s1, const String& s2)
{
	if (s1.m_Data == nullptr || s2.m_Data == nullptr)
		return false;
	return strcmp(s1.m_Data, s2.m_Data) > 0;
}

bool operator<=(const String& s1, const String& s2)
{
	if (s1.m_Data == nullptr || s2.m_Data == nullptr)
		return false;
	return strcmp(s1.m_Data, s2.m_Data) <= 0;;
}

bool operator>=(const String& s1, const String& s2)
{
	if (s1.m_Data == nullptr || s2.m_Data == nullptr)
		return false;
	return strcmp(s1.m_Data, s2.m_Data) >= 0;
}

String operator+(const String& s1, const String& s2)
{
	size_t newLength = s1.m_Length + s2.m_Length;
	char* data = new char[newLength + 1];
	strcpy_s(data, s1.m_Length + 1, s1.m_Data);
	strcat_s(data, newLength + 1, s2.m_Data);
	return String(data);
}

String operator*(const String& s, size_t num)
{
	String result(s);
	for (size_t i = 1; i < num; ++i)
		result += s;
	return result;
}

String operator*(size_t num, const String& s)
{
	return s * num;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << (str.m_Data == nullptr ? "" : str.m_Data);
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buffer[256];
	is >> buffer;
	str = buffer;
	return is;
}
