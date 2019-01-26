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

class list
{
	Node org;	//headnode
public:
	list() : org(0) {}
	~list() { clear(); }
	void clear() { while (!isEmpty())delete remove(0); }
	Node* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == nullptr; }

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

	void replace(int pos, Node*n) {
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
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
	list list;
	list.insert(0, new Node(1.0));
	list.insert(0, new Node(2.0));
	list.insert(1, new Node(3.0));
	list.insert(list.size(), new Node(4.0));
	list.insert(2, new Node(5.0));
	list.display();

	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.display();

	list.replace(1, new Node(9.0));
	list.display();

	list.clear();
	list.display();

	system("pause");
	return 0;
}