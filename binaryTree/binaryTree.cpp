#include <iostream>
#include <cstdio>
using namespace std;

class BinaryNode {
public:
	int data;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
		:data(val), left(l), right(r) {}
	bool isLeaf() { return left == nullptr && right == nullptr; } //단말 확인 함수

	void NodeInorder() {
		if (left != nullptr) left->NodeInorder();
		printf(" [%c] ", data);
		if (right != nullptr) right->NodeInorder();
	}

	void NodePreorder() {
		printf(" [%c] ", data);
		if (left != nullptr) left->NodePreorder();
		if (right != nullptr) right->NodePreorder();
	}

	void NodePostorder() {
		if (left != nullptr) left->NodePostorder();
		if (right != nullptr) right->NodePostorder();
		printf(" [%c] ", data);
	}
};

class BinaryTree {
public:
	BinaryNode* root;
	BinaryTree() : root(nullptr) {}
	bool isEmpty() { return root == nullptr; }

	void inorder() {
		printf("\n inorder   :	");
		if (!isEmpty()) root->NodeInorder();
	}
	void preorder() {
		printf("\n preorder  :	");
		if (!isEmpty()) root->NodePreorder();
	}
	void postorder() {
		printf("\n postorder :	");
		if (!isEmpty()) root->NodePostorder();
	}
	



};

void main()
{

	BinaryTree tree;

	BinaryNode *k = new BinaryNode('k', nullptr, nullptr);
	BinaryNode *h = new BinaryNode('h', nullptr, nullptr);
	BinaryNode *g = new BinaryNode('G', h, k);
	BinaryNode *d = new BinaryNode('D', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', g, NULL);
	BinaryNode *b = new BinaryNode('B', d, e);
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *c = new BinaryNode('C', f, NULL);
	BinaryNode *a = new BinaryNode('A', b, c);

	tree.root = a;
	
	tree.inorder();
	tree.preorder();
	tree.postorder();
	printf("\n");
	system("pause");
}
