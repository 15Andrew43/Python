#include "queue.h"

#include <utility>

void Rehandling(Stack& Left, Stack& Right) {
	while(!Left.Empty()) {
		Right.Push(Left.Top());
		Left.Pop();
	}
}

void Queue::Push(Type value) {
	Left.Push(value);
}

void Queue::Pop() {
	if (Right.Empty()) {
		Rehandling(Left, Right);
	}
	Right.Pop();
}

Type& Queue::Front() {
	if (Right.Empty()) {
		Rehandling(Left, Right);
	}
	return Right.Top();
}

Type Queue::Front() const {
	if (Right.Empty()) {
		Stack copied_to;
		Copy(Left, copied_to);
		return copied_to.Top();		
	}	
	return Right.Top();
}

void Queue::Clear() {
	Left.Clear();
	Right.Clear();
}
bool Queue::Empty() const {
	return (Left.Size() + Right.Size()) == 0;
}
size_t Queue::Size() const {
	return Left.Size() + Right.Size();
}