#include <iostream>

#include <cstring>

#include "string.h"


void Rewrite(char*& buffer_, const char* other_buffer, const size_t capacity_) {
	char* old_buffer = buffer_;
	buffer_ = new char[capacity_];
	Copy(buffer_, other_buffer);
	delete[] old_buffer;
}

void Copy(char* buffer_, const char* str) {
	size_t L = strlen(str);
	for (size_t i = 0; i < L; ++i) {
		buffer_[i] = str[i];
	}
}

void ChCapacity(size_t& Capacity, const size_t& new_size, size_t kIncreaseFactor = 2) {
	while (Capacity < new_size) {
		Capacity *= kIncreaseFactor;
	}
}

void Fill(size_t new_size, String& string, char fill = 'a') {
	for (int i = string.Size(); i < new_size; ++i) {
		string[i] = fill;
	}
}



String::String() {
	buffer_ = new char[capacity_];
}

String::String(const char* str) {
	size_ = strlen(str);
	ChCapacity(capacity_, size_);

	buffer_ = new char[capacity_];
	Copy(buffer_, str);
}

String::String(const char* str, size_t n) {
	capacity_ = n;
	size_ = n;

	buffer_ = new char[capacity_];
	Copy(buffer_, str);
}

String::String(size_t size, char symbol) {
	ChCapacity(capacity_, size);
	size_ = size;

	buffer_ = new char[capacity_];
	buffer_[0] = symbol;
}

String::String(const String& other) {
	String(); // работает и без этой строчки!!!!!!!!!!!!?????????
	*this = other;
}	

										//ссылка на указаьель работает!
String& String::operator=(const String& other) {
	size_t L = other.Size();
	size_ = L;

	ChCapacity(capacity_, other.Capacity());
	
	Rewrite(buffer_, other.buffer_, capacity_);
//	char* old_buffer = buffer_;
//	buffer_ = new char[capacity_];
//	Copy(buffer_, other.buffer_);
//	delete[] old_buffer;
	
	return *this;
}

String::~String() {
	delete[] buffer_;
}



size_t String::Size() const {
	return size_;
}
size_t String::Length() const {//		сделать по человечески
	return Size();
}

size_t String::Capacity() const {
	return capacity_;
}

void String::Resize(size_t new_size, char fill = 'a') {
	size_t old_capacity = capacity_;

	if (new_size <= Size()) {
		(*this)[new_size] = '\0';
	} else {
		if (new_size > capacity_) {
			ChCapacity(capacity_, new_size);
			Rewrite(buffer_, buffer_, capacity_);
//			char* old_buffer = buffer_;
//			buffer_ = new char[capacity_];
//			Copy(buffer_, old_buffer);
//			delete[] old_buffer;
		} 
		Fill(new_size, *this);
	}

	size_ = new_size;
}

bool String::Empty() const {
	return size_ == 0;
}
void String::Clear() {
	buffer_[0] = '\0';
	size_ = 0;
}

// change capacity!
void String::Reserve(size_t new_capacity) {
	if (new_capacity < size_) {
		buffer_[new_capacity] = '\0';
	} else {
		capacity_ = new_capacity;
		Rewrite(buffer_, buffer_, capacity_);
//		char* old_buffer = buffer_;
//		buffer_ = new char[capacity_];
//		Copy(buffer_, old_buffer);
//		delete[] old_buffer;
	}
}

void String::ShrinkToFit() {
	capacity_ = Size();
}

char& String::Back() {
//	return buffer_[size_];
	return (*this)[Size()-1];
}
char& String::Front() {	
//	return (buffer_)[0];
	return (*this)[0];
}



char String::operator[](size_t idx) const { // ok даже если элеметнов 10, а можно так - s[200]
	return buffer_[idx];
}
char& String::operator[](size_t idx) {
	return buffer_[idx];
}



const char* String::CStr() const {
	return buffer_;
}
const char* String::Data() const {//		переписать по-человечески
	return CStr();
}



String& String::operator+=(const String& other) {
	size_t size_ = Size() + other.Size();
	ChCapacity(capacity_, size_);

	for (size_t j=0, i=Size(); i < size_; ++i, ++j) {
		(*this)[i] = other[j];
	}
	return *this;
}

String& String::operator+=(char symbol) {
	++size_;
	ChCapacity(capacity_, size_);

	(*this)[Size()-1] = symbol;

	return (*this);
}

void String::PushBack(char symbol) {
	(*this) += symbol;
}
void String::PopBack() {
	(*this)[Size()-1] = '\0';
	--size_;
}

String operator+(const String& lhs, const String& rhs) {
	String string = lhs;
	string += rhs;
	return string;
}
String operator+(char symbol, const String& rhs) {
	String string;
	string += symbol;
	string += rhs;
	return string;
}
String operator+(const String& rhs, char symbol) {
	String string;
	string += rhs;
	string += symbol;
	return string;
}
/* ?????????????????????????????????????????????????????????????????????????????????????
String operator+(char symbol_lhs, char symbol_rhs) {
	String string;
	string += symbol_lhs;
	string += symbol_rhs;
	return string;
}
*/
