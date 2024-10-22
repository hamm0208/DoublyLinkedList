#include <iostream>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#include "List.h"

using namespace std;

int main() {
	List<int> myList;
	for (int x = 1; x <= 5; x++) {
		myList.push(x);
	}
	cout << "List after pushing 5 intergers:" << endl;
	for (auto it = myList.getIteratorHead(); it != it.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl;

	myList.pop();
	myList.pop();
	cout << "List after popping 2 nodes:" << endl;
	for (auto it = myList.getIteratorHead(); it != it.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
	
}
	/*
	DoublyLinkedNode<int>* Head;
	Head = new DoublyLinkedNode<int>(1);
	Head->append(new DoublyLinkedNode<int>(2));
	Head->append(new DoublyLinkedNode<int>(3));
	Head->append(new DoublyLinkedNode<int>(4));
	Head->append(new DoublyLinkedNode<int>(5));

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
	for (DoublyLinkedNodeIterator<int> iter(Head); iter != iter.end(); iter++) {
		cout << *iter << endl;
	}

	DoublyLinkedNodeIterator<int> iterEnd(Head);
	while (iterEnd != iterEnd.end()) {
		DoublyLinkedNode<int>* Temp = iterEnd.getCurrent();
		++iterEnd;
		Temp->remove();
	}
	*/