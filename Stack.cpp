#include "stdafx.h"

#include "Stack.h"
#include <iostream>

template <class T, class S>
Stack<T, S>::Stack() {
	stackTop = NULL;
}

template <class T, class S>
Stack<T, S>::~Stack() {
	struct Node *cur = stackTop;
	struct Node *next;
	while (cur != NULL) {
		next = cur->next;
		free((T*)cur->data);
		free(cur);
		cur = next;
	}
	stackTop = NULL;
}

template <class T, class S>
void Stack<T, S>::push(T **data) {
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = (void *)(*data);
	new_node->next = stackTop;
	stackTop = new_node;
}


template <class T, class S>
bool Stack<T, S>::peek(S *topVal) {
	if (stackTop != NULL) {
		*topVal = (S)(((T*)(stackTop->data))->data);
		return true;
	}

	return false;
}

template <class T, class S>
bool Stack<T, S>::pop(T **top) {
	if (stackTop != NULL) {
		struct Node *cur = stackTop;
		*top = (T*)(cur->data);
		stackTop = cur->next;
		free(cur);
		return true;
	}

	return false;
}

template <class T, class S>
bool Stack<T, S>::isEmpty() {
	return stackTop == NULL ? true : false;
}