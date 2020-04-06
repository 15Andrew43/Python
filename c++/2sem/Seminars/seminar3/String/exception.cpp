#include <iostream>

#include <cstring>

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
}
