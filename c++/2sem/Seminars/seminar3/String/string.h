#ifndef STRING_H 
#define STRING_H

#include <utility>

class String {
	char* buffer_;
	size_t size_;
	size_t capacity_ = 1;

	const static size_t kIncreaseFactor = 2;

public:
	String();
	String(const char* str);
	String(const char* str, size_t n);
	String(size_t size, char symbol);
	
	String(const String& other);
	String& operator=(const String& other);
	~String();

	size_t Size() const;
	size_t Length() const; // ?????????????????????????????
	size_t Capacity() const;
	void Resize(size_t new_size, char fill);
	bool Empty() const;
	void Clear();
	void Reserve(size_t new_capacity);
	void ShrinkToFit();

//////////// REMOVE THIS IF YOU ARE IMPLEMENTING COW //////////// BEGIN
	char& Back();
	char& Front();

	char operator[](size_t idx) const;
	char& operator[](size_t idx);

//////////// REMOVE THIS IF YOU ARE IMPLEMENTING COW //////////// END

	const char& Back() const;
	const char& Front() const;

//////////// UNCOMMENT THIS IF YOU ARE IMPLEMENTING COW //////////// BEGIN
/*	const char& Get(size_t idx) const;         // operator[] analogue
	void Set(size_t idx, char symbol);  // operator[] analogue
*/
//////////// UNCOMMENT THIS IF YOU ARE IMPLEMENTING COW //////////// END

	const char* CStr() const;
	const char* Data() const;

	String& operator+=(const String& other);
	String& operator+=(char symbol);

	void PushBack(char symbol);
	void PopBack();

};

String operator+(const String& lhs, const String& rhs);
String operator+(char symbol, const String& rhs);
String operator+(const String& rhs, char symbol);
//String operator+(char symbol_lhs, char symbol_rhs); ???????????????????????????????????????????????

// < > >= <= == !=

// operator>>
// operator<<

void Copy(char* buffer_, const char* str);

#endif