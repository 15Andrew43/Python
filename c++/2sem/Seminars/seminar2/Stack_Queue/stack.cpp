#include <iostream>

#include "stack.h"

#include <utility>

#include "exception.h"

void Stack::Push(Type value) {
	Node* new_node = new Node;
	new_node->value_ = value;
	new_node->prev = head_;
	head_ = new_node;
	++size_;
}

void Stack::Pop() {
<<<<<<< HEAD
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Pop() in stack, because size = 0");
	}
	Node* old_head = head_;
	head_ = head_->prev;
	delete old_head;
	--size_;
}

Type Stack::Top() const {
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Top() in stack, because size = 0");
	}
	return head_->value_;
}

Type& Stack::Top() {
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Top() in stack, because size = 0");
	}
	return head_->value_;
=======
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		Node* old_head = head_;
		head_ = head_->prev;
		delete old_head;
		--size_;
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя pop()\n";
		throw;
	}
}

Type Stack::Top() const {
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		return head_->value_;
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя Top()\n";
		throw;
	}
}

Type& Stack::Top() {
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		return head_->value_;
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя Top()\n";
		throw;
	}
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
}

void Stack::Clear() {
	while (head_) {
		Node* old_head = head_;
		head_ = head_->prev;
		delete old_head;
	}
	size_ = 0;
}

bool Stack::Empty() const {
	return size_ == 0;
}
size_t Stack::Size() const {
	return size_;
}

void Copy(Node* ptr, Stack& stack) {
	while (ptr) {
		stack.Push(ptr->value_);
		ptr = ptr->prev;
	}
}

Stack::Stack(const Stack& other) {
	Stack stack;
	Copy(other.head_, stack);
	Copy(stack.head_, *this);
}



Stack& Stack::operator=(const Stack& other) {
	if (&other != this) {
		Stack stack;
		Copy(other.head_, stack);
		Copy(stack.head_, *this);
	}
	return *this;
}

Stack::~Stack() {
	Clear();
}
