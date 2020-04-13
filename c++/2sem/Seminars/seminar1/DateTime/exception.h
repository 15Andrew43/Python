#ifndef EXCEPTION_H 
#define EXCEPTION_H

<<<<<<< HEAD
//#include <iostream>
#include <string>

class Exception {
	std::string message_error_ = "error!";
public:
	Exception() = default;
	Exception(const std::string& message_error);
	virtual std::string what() const;
};


class LogicError : public Exception {
	std::string message_error_ = "logic error!";
public:
	LogicError() = default;
	LogicError(const std::string& message_error);
	virtual std::string what() const;
};
class RuntimeError : public Exception {
	std::string message_error_ = "runtime error!";
public:
	RuntimeError() = default;
	RuntimeError(const std::string& message_error);
	virtual std::string what() const;
};
class BadAlloc : public Exception {
	std::string message_error_ = "bad allocation!";
public:
	BadAlloc() = default;
	BadAlloc(const std::string& message_error);
	virtual std::string what() const;
};


class InvalidArgument : public LogicError {
	std::string message_error_ = "invalid argument!";
public:
	InvalidArgument() = default;
	InvalidArgument(const std::string& message_error);
	std::string what() const;
};
class DomainError : public LogicError {
	std::string message_error_ = "domain error!";
public:
	DomainError() = default;
	DomainError(const std::string& message_error);
	std::string what() const;
};
class LengthError : public LogicError {
	std::string message_error_ = "length error!";
public:
	LengthError() = default;
	LengthError(const std::string& message_error);
	std::string what() const;
};
class OutOfRange : public LogicError {
	std::string message_error_ = "out of range!";
public:
	OutOfRange() = default;
	OutOfRange(const std::string& message_error);
	std::string what() const;
};


class RangeError : public RuntimeError {
	std::string message_error_ = "range error!";
public:
	RangeError() = default;
	RangeError(const std::string& message_error);
	std::string what() const;
};
class OverflowError : public RuntimeError {
	std::string message_error_ = "overflow error!";
public:
	OverflowError() = default;
	OverflowError(const std::string& message_error);
	std::string what() const;
};
class UnderflowError : public RuntimeError {
	std::string message_error_ = "underflow error!";
public:
	UnderflowError() = default;
	UnderflowError(const std::string& message_error);
	std::string what() const;
=======
class exception {
public:
	virtual const char* what();
};


class logic_error : public exception {
public:
	virtual const char* what();
};
class runtime_error : public exception {
public:
	virtual const char* what();
};
class bad_alloc : public exception {
public:
	virtual const char* what();
};


class invalid_argument : public logic_error {
public:
	const char* what();
};
class domain_error : public logic_error {
public:
	const char* what();
};
class length_error : public logic_error {
public:
	const char* what();
};
class out_of_range : public logic_error {
public:
	const char* what();
};


class range_error : public runtime_error {
public:
	const char* what();
};
class overflow_error : public runtime_error {
public:
	const char* what();
};
class underflow_error : public runtime_error {
public:
	const char* what();
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
};


#endif