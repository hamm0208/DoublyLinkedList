#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#pragma once

template<class T>
class List
{
	private:
		typedef DoublyLinkedNode<T> Node;
		Node* last;
		Node* head;
		int count;
	public:
		typedef DoublyLinkedNodeIterator<T> Iterator;

		List() : last(&(Node::NIL)), head(&(Node::NIL)), count(0) {};
		List(Node* firstNode) : last(firstNode), head(firstNode), count(1) {};

		~List() {
			Iterator it = getIteratorLast();
			while (it != it.end()) {
				Node* toDelete = it.getCurrent();
				--it;
				toDelete->remove();
			}
		}
		bool isEmpty() const{
			return count == 0;
		}
		int size() const {
			return count;
		}
		void push(const T& value) {
			Node* newNode = new Node(value);
			if (last != &(Node::NIL)) {
				last->append(newNode);
			}
			if (head == &(Node::NIL)) {
				head = newNode;
			}
			last = newNode;
			++count;
		}
		Node* pop() {
			if (last != &(Node::NIL)) {
				Node* toDelete = last;
				last = last->getPrevious();
				toDelete->remove();
				--count;
			}
		}
		Iterator getIteratorLast() const {
			return Iterator(last);
		}
		Iterator getIteratorHead() const {
			return Iterator(head);
		}
};

