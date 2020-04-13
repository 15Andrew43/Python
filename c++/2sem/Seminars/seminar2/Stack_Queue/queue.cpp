#include <iostream>

#include "queue.h"

#include <utility>

#include "exception.h"

void Rehandling(Stack& Left, Stack& Right) {
	while(Left.Size()) {
		Right.Push(Left.Top());
		Left.Pop();
	}
}

void Queue::Push(Type value) {
	Left.Push(value);
}

void Queue::Pop() {
<<<<<<< HEAD
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Pop() in queue, because size = 0");
	}
	if (Right.Empty()) {
		Rehandling(Left, Right);
=======
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		if (Right.Empty()) {
			Rehandling(Left, Right);
		}
		Right.Pop();
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя Pop()\n";
		throw;
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
	}
}

Type& Queue::Front() {
<<<<<<< HEAD
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Front() in queue, because size = 0");
	}
	if (Right.Empty()) {
		Rehandling(Left, Right);
=======
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		if (Right.Empty()) {
			Rehandling(Left, Right);
		}
		return Right.Top();
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя Top()\n";
		throw;
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
	}
}

Type Queue::Front() const {
<<<<<<< HEAD
	if (Size() == 0) {
		throw LogicError("Logic Error: you can't use Front() in queue, because size = 0");
	}
	if (Right.Empty()) {
		Node* ptr = Left.head_;
		while (ptr -> prev) {
			ptr = ptr -> prev;
		}
		return ptr -> value_;
	}	
	return Right.Top();
=======
	try {
		if (Size() == 0) {
			throw logic_error();
		}
		if (Right.Empty()) {
			Node* ptr = Left.head_;
			while (ptr -> prev) {
				ptr = ptr -> prev;
			}
			return ptr -> value_;
		}	
		return Right.Top();
	} catch (exception& ex) {
		std::cout << "size = 0, нельзя Front()\n";
		throw;
	}
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
}

void Queue::Clear() {
	Left.Clear();
	Right.Clear();
}
bool Queue::Empty() const {
	return Left.size_ + Right.size_== 0;
}
size_t Queue::Size() const {
	return Left.size_ + Right.size_;
}