#pragma once
// ����Ž��Ʈ��

struct Node
{
	Node() {}
	Node(int key) : key(key) {}

	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;

	int key = -1; // key �� �������� ����
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

		// tree�� ���ּ�ȸ ����

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

		// node1�� �θ��ʿ��� ���ʿ� �ִ� �ڽ��̳�?
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