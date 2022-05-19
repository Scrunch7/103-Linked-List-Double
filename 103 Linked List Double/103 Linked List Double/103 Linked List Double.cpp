#include <iostream>
#include "ListNodeDouble.h"


void run(Node* node) {
	while (node->postNode != NULL) {
		std::cout << node->i_data;
		node = node->postNode;
	}
}

void clear(Node* clearFrom) {
	Node* next = clearFrom->postNode;
	clearFrom->postNode = NULL;
	clearFrom = next;
	while (next != NULL) {
		next = clearFrom->postNode;
		delete(clearFrom);
		clearFrom = next;
	}
}


int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node(1);
	second = new Node(2);
	third = new Node(3);


	//Initialize
	std::cout << "Initial Run--------------\n\n";
	head->prevNode = NULL;		head->i_data = 1;		head->postNode = second;
	second->prevNode = head;	second->i_data = 2;		second->postNode = third;
	third->prevNode = second;	third->i_data = 3;

	run(head);


	//Add to end
	std::cout << "\n\nAdding to end---------------\n\n";
	Node* tail = NULL;
	tail = new Node(0);
	tail->i_data = 0;		 tail->Append(third, tail);

	run(head);


	//Add to start
	std::cout << "\n\nAdd to start--------------\n\n";
	Node* newHead = NULL;
	newHead = new Node(0);
	newHead->Reassign(head, newHead);

	run(newHead);

	//Insert
	std::cout << "\n\nInsert at point------------\n\n";
	Node* insertedNode = NULL;
	insertedNode = new Node(8);
	insertedNode->Insert(head, second, insertedNode);
	run(newHead);

	clear(insertedNode);
	run(newHead);


}