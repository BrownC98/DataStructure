#include <iostream>

using namespace std;

class Node {
	Node* prev;
	Node* next;
	int data;
public:
	Node(int i = 0)
		:data(i), prev(nullptr), next(nullptr) {}


	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	void setPrev(Node* p) { prev = p; }
	void setNext(Node* p) { next = p; }
	void display() { printf(" %2d", data); }
	bool hasData(int val) { return data == val; }
	int getData() { return data; }

	void insertNext(Node *n) {
		if (n != nullptr) {
			n->prev = this;
			n->next = next;
			if (next != nullptr) next->prev = n;//
			next = n;
		}
	}

	Node* remove() {
		if (prev != nullptr) prev->next = next;
		if (next != nullptr) next->prev = prev;
		return this;
	}
};

class deque
{
	Node org;	//headnode
public:
	deque() : org(0) {}
	~deque() { clear(); }
	void clear() { while (!isEmpty())delete remove(0); }
	Node* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == nullptr; }

	void addFront(Node* n)	{ insert(0, n); }
	Node* deletFront() { return remove(0); }
	Node* getFront() { return getEntry(0); }
	void addRear(Node* n) { insert(size(), n); }
	Node* deleteRear() { return remove(size() - 1); }
	Node* getRear() { return getEntry(size() - 1); }

	//이동하다 끊기면 끊긴 노드 반환
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == nullptr) break;
		return n;
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr)
			prev->insertNext(n);
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos);
		return prev->remove();
	}

	Node* find(int val) {
		for (Node*p = getHead(); p != nullptr; p = p->getNext())
			if (p->hasData(val)) return p;
		return nullptr;
	}


	int size() {
		int count = 0;
		for (Node* p = getHead(); p != nullptr; p = p->getNext())
			count++;
		return count;
	}

	void display() {
		printf("전체항목 수 : %d\n", size());
		for (Node*p = getHead(); p != nullptr; p = p->getNext())
			p->display();
		printf("\n");
	}
};



int main(void) {
	deque deque;
	
	for (int i = 0; i < 10; i++) {
		if (i % 2) deque.addFront(new Node(i));
		else deque.addRear(new Node(i));
	}
	deque.display();

	delete deque.deletFront();
	delete deque.deleteRear();
	delete deque.deletFront();
	deque.display();

	system("pause");
	return 0;
}