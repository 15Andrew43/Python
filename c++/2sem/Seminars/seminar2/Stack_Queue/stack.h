#ifndef STACK_H
#define STACK_H

#include <cstddef> // size_t

typedef int Type;

struct Node {
	Type value_;
	Node* prev;
};
/*
queue.cpp:33:14: error: member access into incomplete type 'Node'
                while (ptr -> prev) {
                           ^
./stack.h:8:8: note: forward declaration of 'Node'
struct Node;
*/


class Stack {
	Node* head_ = nullptr;
	size_t size_ = 0;
public:
	void Push(Type value);
	void Pop();
	Type Top() const;
	Type& Top();
	
	void Clear();
	bool Empty() const;
	size_t Size() const;

//	нарушено правило трех, то есть надо написать конструктор, но какой?
//	Stack();

	Stack& operator=(const Stack& other);

	~Stack();

//	friend class Queue;
};

void Copy(const Stack& from, Stack& to);

#endif