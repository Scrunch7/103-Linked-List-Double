#pragma once
#include <cstddef>
class Node {
public:
	Node* prevNode;
	int i_data = 0;
	Node* postNode;
	Node(int i) {
		prevNode = NULL;
		postNode = NULL;
		i_data = i;
	}

	//Function to add new Node to end
	void Append(Node* tail, Node* newTail) {
		tail->postNode = newTail;
		newTail->prevNode = tail;
	}

	//Function to add new Node to start
	void Reassign(Node* head, Node* newHead) {
		newHead->postNode = head;
		head->prevNode = newHead;
	}
	void Insert(Node* from, Node* to, Node* newNode) {
		from->postNode = newNode;
		newNode->postNode = to;
		to->prevNode = newNode;
		newNode->prevNode = from;
	}
};
