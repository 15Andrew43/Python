#include <iostream>

#include <cstring>
<<<<<<< HEAD
#include <string>

#include "exception.h"

Exception::Exception(const std::string& message_error) {
	message_error_ = message_error;
}
std::string Exception::what() const {
	return message_error_;
}

LogicError::LogicError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string LogicError::what() const {
	return message_error_;
}
RuntimeError::RuntimeError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string RuntimeError::what() const {
	return message_error_;
}
BadAlloc::BadAlloc(const std::string& message_error) {
	message_error_ = message_error;
}
std::string BadAlloc::what() const {
	return message_error_;
}

InvalidArgument::InvalidArgument(const std::string& message_error) {
	message_error_ = message_error;
}
std::string InvalidArgument::what() const {
	return message_error_;
}
DomainError::DomainError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string DomainError::what() const {
	return message_error_;
}
LengthError::LengthError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string LengthError::what() const {
	return message_error_;
}
OutOfRange::OutOfRange(const std::string& message_error) {
	message_error_ = message_error;
}
std::string OutOfRange::what() const {
	return message_error_;
}

RangeError::RangeError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string RangeError::what() const {
	return message_error_;
}
OverflowError::OverflowError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string OverflowError::what() const {
	return message_error_;
}
UnderflowError::UnderflowError(const std::string& message_error) {
	message_error_ = message_error;
}
std::string UnderflowError::what() const {
	return message_error_;
=======

#include "exception.h"

const char* exception::what() {
	return "error!";
}


const char* logic_error::what() {
	return "logic error!";
}
const char* runtime_error::what() {
	return "runtime error!";
}
const char* bad_alloc::what() {
	return "bad alloc!";
}


const char* invalid_argument::what() {
	return "passing an invalid argument to the function";
}
const char* domain_error::what() {
	return "the result for the function from some value is not defined";
}
const char* length_error::what() {
	return "exceeded the maximum allowed size for some type";
}
const char* out_of_range::what() {
	return "access to elements outside the allowed range";
}


const char* range_error::what() {
	return "the result exceeds the allowed range";
}
const char* overflow_error::what() {
	return "result exceeds the allowed range";
}
const char* underflow_error::what() {
	return "the result obtained in calculations has an invalid negative value (exceeding the lower allowed value limit)";
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
}
