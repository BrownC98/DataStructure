#include <iostream>

using namespace std;

class Node {
	Node* link;
public:
	Node(int i = 0)
		:data(i), link(nullptr) {}
	int data;

	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }

};

class Queue {
	Node* front; //first
	Node* rear;	 //last
public:
	Queue():front(nullptr), rear(nullptr) { }
	~Queue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == nullptr; }

	void enqueue(Node *p) {
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}

	Node* dequeue() {
		if (isEmpty()) return nullptr;
		Node *p = front;
		front = front->getLink();
		if (front == nullptr) rear = nullptr;
		return p;
	}

	Node* peek() { return front; }

	void display() {
		for (Node *p = front; p != nullptr; p = p->getLink())
			printf("%d\n", p->data);
	}
};
int main(void) {
	Queue queue;
	queue.enqueue(new Node(1));
	queue.enqueue(new Node(2));
	queue.enqueue(new Node(3));
	queue.enqueue(new Node(4));
	queue.enqueue(new Node(5));

	queue.display();
	cout << '\n';
	queue.dequeue();
	queue.dequeue();

	queue.display();
	return 0;
}