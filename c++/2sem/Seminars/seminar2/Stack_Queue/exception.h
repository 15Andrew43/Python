#ifndef EXCEPTION_H 
#define EXCEPTION_H

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
};


#endif