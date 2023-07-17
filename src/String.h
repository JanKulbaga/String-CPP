#pragma once

#include <cstring>
#include <iostream>

class StringIterator
{
public:
	StringIterator(char* ptr)
		: m_Ptr(ptr)
	{}

	StringIterator& operator++() { ++m_Ptr; return *this; }
	StringIterator operator++(int) { StringIterator tmp = *this; ++m_Ptr; return tmp; }

	char& operator*() const { return *m_Ptr; }
	bool operator==(const StringIterator& other) const { return m_Ptr == other.m_Ptr; }
	bool operator!=(const StringIterator& other) const { return m_Ptr != other.m_Ptr; }
private:
	char* m_Ptr{ nullptr };
};

class StringReverseIterator
{
public:
	StringReverseIterator(char* ptr)
		: m_Ptr(ptr)
	{}

	StringReverseIterator& operator++() { --m_Ptr; return *this; }
	StringReverseIterator operator++(int) { StringReverseIterator tmp = *this; --m_Ptr; return tmp; }

	char& operator*() const { return *m_Ptr; }
	bool operator==(const StringReverseIterator& other) const { return m_Ptr == other.m_Ptr; }
	bool operator!=(const StringReverseIterator& other) const { return m_Ptr != other.m_Ptr; }
private:
	char* m_Ptr{ nullptr };
};

class String
{
public:
	using Iterator = StringIterator;
	using ReverseIterator = StringReverseIterator;
public:
	String() = default;
	String(char c);
	String(const char* const str);
	String(const String& other);
	~String();

	String& operator=(const String& other);
	String& operator=(const char* const str);
	String& operator=(char c);
	friend bool operator==(const String& s1, const String& s2);
	friend bool operator!=(const String& s1, const String& s2);
	friend bool operator<(const String& s1, const String& s2);
	friend bool operator>(const String& s1, const String& s2);
	friend bool operator<=(const String& s1, const String& s2);
	friend bool operator>=(const String& s1, const String& s2);
	friend String operator+(const String& s1, const String& s2);
	String& operator+=(const String& other);
	friend String operator*(const String& s, size_t num);
	friend String operator*(size_t num, const String& s);
	String& operator*=(size_t num);
	char& operator[](size_t index);
	char& operator[](size_t index) const;

	char& back() const;
	void clear();
	const char* c_str() const;
	bool endsWith(const char* const str) const;
	int64_t find(const char* const str) const;
	char& front() const;
	bool isAlpha() const;
	bool isDigit() const;
	bool isSpace() const;
	bool isEmpty() const;
	size_t length() const;
	String lower() const;
	String trim() const;
	String trimEnd() const;
	String trimStart() const;
	bool startsWith(const char* const str) const;
	String substring(size_t start, size_t end) const;
	String upper() const;
	String zfill(size_t num) const;

	Iterator begin();
	Iterator end();
	Iterator cbegin() const;
	Iterator cend() const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	ReverseIterator crbegin() const;
	ReverseIterator crend() const;

	static String asciiLetters();
	static String asciiLowercase();
	static String asciiUppercase();
	static String digits();
	static String FromNumber(size_t num);
	static String hexdigits();
	static String octdigits();
	static String punctuation();

	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
private:
	char* m_Data { nullptr };
	size_t m_Length { 0 };
};
