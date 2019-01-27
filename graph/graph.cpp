#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX_VERTEX 256

class matGraph {
	int size;
	char vertices[MAX_VERTEX];
	int adj[MAX_VERTEX][MAX_VERTEX];
public:
	matGraph()							{ reset(); }
	char getVertex(int i)				{ return vertices[i]; }
	int getEdge(int i, int j)			{ return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	bool isEmpty()	{ return size == 0; }
	bool isFull()	{ return size >= MAX_VERTEX; }

	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VERTEX; i++)
			for (int j = 0; j < MAX_VERTEX; j++)
				setEdge(i, j, 0);
	}

	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
	}

	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display() {
		printf("정점개수 : %d\n   ", size);
		for (int i = 0; i < size; i++) 
			printf("%3c ", 'A'+ i);
		printf("\n");
		for (int i = 0; i < size; i++) {
			printf("%c ", getVertex(i));
			for (int j = 0; j < size; j++)
				printf(" %3d", getEdge(i, j));
			printf("\n");
		}
	}
};

void main() {
	int size;
	matGraph g;
	srand((unsigned)time(NULL));

	printf("랜덤 그래프생성, 정점개수를 입력하세요\n");
	std::cin >> size;

	printf("\n");
	for (int i = 0; i < size; i++)
		g.insertVertex('A' + i);
	for (int i = 0; i < size; i++)
		g.insertEdge(rand() % (size+1), rand() % (size + 1));
	
	printf("결과 출력\n");
	g.display();
	system("pause");
}