#include <iostream>
#include "stack.h"

#include <utility>

void Stack::Push(Type value) {
	Node* new_node = new Node {value, head_};
	head_ = new_node;
	++size_;
}

void Stack::Pop() {
	Node* old_head = head_;
	head_ = head_->prev;
	delete old_head;
	--size_;
}

Type Stack::Top() const {
	return head_->value_;
}

Type& Stack::Top() {
	return head_->value_;
}

bool Stack::Empty() const {
	return size_ == 0;
}

void Stack::Clear() {
	while (!Empty()) {
		Pop();
		std::cout << "---------________________+++++++++\n";
//		Node* old_head = head_;
//		head_ = head_->prev;
//		--size_;
//		delete old_head;
	}
//	size_ = 0;
	std::cout << "end cleaning\n";
}


size_t Stack::Size() const {
	return size_;
}


void Copy(const Stack& from, Stack& to) {
	Stack copied_from = from;
	while (!(copied_from.Empty())) {
		to.Push(copied_from.Top());
		copied_from.Pop();
	}
}


Stack& Stack::operator=(const Stack& other) {
	if (&other != this) {
		Stack stack;
		Copy(other, stack);
		Copy(stack, *this);
	}
	return *this;
}

Stack::~Stack() {
	Clear();
}
