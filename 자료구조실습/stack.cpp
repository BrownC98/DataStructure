#include <iostream>

using namespace std;

class Node{
	Node* link;
public:
	Node(int i = 0)
		:data(i), link(nullptr) {}
	int data;

	Node* getLink() { return link;}
	void setLink(Node* p) { link = p; }
	
};

class Stack {
	Node* top;
public:
	Stack() { top = nullptr; }
	~Stack() {while (!isEmpty()) delete pop();}
	bool isEmpty() { return top == nullptr; }

	void push(Node *p) {
		if (isEmpty()) top = p;
		else {
			p->setLink(top);
			top = p;
		}
	}

	Node* pop() {
		if (isEmpty()) return nullptr;
		Node *p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() { return top; }

	void display() {
		for (Node *p = top; p != nullptr; p = p->getLink())
			printf("%d\n", p->data );	
	}
};
int main(void) {
	Stack stack;

	stack.push(new Node(1));
	stack.push(new Node(2));
	stack.push(new Node(3));
	stack.push(new Node(4));
	stack.push(new Node(5));

	stack.display();
	cout << endl;

	stack.pop();
	stack.pop();

	stack.display();
	system("pause");
	return 0;
}