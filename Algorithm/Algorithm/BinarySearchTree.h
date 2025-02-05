#pragma once
// 이진탐색트리

struct Node
{
	Node() {}
	Node(int key) : key(key) {}

	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;

	int key = -1; // key 를 기준으로 정렬
	int data = 0; 

	

};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree() {}

	void Insert(int key);
	void PrintTree(Node* node)
	{
		if (node == nullptr)
			return;

		// tree의 전휘순회 지금

	}

	void Delete(Node* node)
	{

	}

	Node* root = nullptr;
private:
	void Replace(Node* node1, Node* node2)
	{
		if (node1->parent == nullptr)
			root = node2;

		// node1이 부모쪽에서 왼쪽에 있는 자식이냐?
		else if (node1 == node1->parent->left)
		{
			node1->parent->left = node2;
		}
		else
		{
			node1->parent->right = node2;
		}

		if (node2 != nullptr)
		{

		}
	}
};