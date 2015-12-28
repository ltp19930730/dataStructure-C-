#include<iostream>
using namespace std;
class Node {
public:
	Node* leftChild;
	Node* rightChild;
	int data;
};



class Tree {
private:
	Node* head;
public:
	Tree()
	{
		head = new Node;
		head->leftChild = nullptr;
		head->rightChild = nullptr;
		head->data = 0;
	}

};