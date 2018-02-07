//#pragma once: A non-standard way

#ifndef __STACK_H
#define __STACK_H

struct Node {
	void *data;
	struct Node *next;
};

template <class T, class S>
class Stack {
private:
	struct Node *stackTop;

public:
	Stack();
	virtual ~Stack();

	void push(T **data);
	bool peek(S *topVal);
	bool pop(T **top);
	bool isEmpty();
};


#endif
