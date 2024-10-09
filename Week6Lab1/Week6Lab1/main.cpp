#include <iostream>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

using namespace std;

int main() {
	DoublyLinkedNode<int>* Head;
	Head = new DoublyLinkedNode<int>(1);
	Head->append(new DoublyLinkedNode<int>(2));
	Head->append(new DoublyLinkedNode<int>(3));
	Head->append(new DoublyLinkedNode<int>(4));
	Head->append(new DoublyLinkedNode<int>(5));

	/*
	DoublyLinkedNode<int>* Ptr;
	Ptr = Head;
	while (Ptr != &(DoublyLinkedNode<int>::NIL)) {
		cout << Ptr->getValue() << endl;
		Ptr = Ptr->getNext();
	}
	Ptr = Head;
	while (Ptr != &(DoublyLinkedNode<int>::NIL)) {
		DoublyLinkedNode<int>* Temp = Ptr;
		Ptr = Ptr->getNext(); //Point first then delete
		delete Temp;
	}
	*/
	for (DoublyLinkedNodeIterator<int> iter(Head); iter != iter.end(); iter++) {
		cout << *iter << endl;
	}

	DoublyLinkedNodeIterator<int> iterEnd(Head);
	while (iterEnd != iterEnd.end()) {
		DoublyLinkedNode<int>* Temp = iterEnd.getCurrent();
		++iterEnd;
		Temp->remove();
	}
	return 0;
}