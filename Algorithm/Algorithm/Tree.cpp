#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>


using namespace std;

// �����ڷᱸ��
// vector
// list
// queue
// stack

// �����ڷᱸ��
// graph
// tree(map)
// unordered_map (hash_table)
// map

// tree
// 1. ���������� �����ϱ� ���� ����
// - �θ���� �ڽĳ��� �̷�����ִ� ����
// => ��� Ʈ������ �ֻ��� �θ��尡 �� �ϳ� �ִ�. (Root ���)
// => ��� Ʈ������ �������� ��������尡 �ִ�. (leaf ���)
// 2. Ʈ���� �߶� Ʈ����.
// => ����Ʈ���� �����Ѵ�
// => ��������� �ڽ��� Ÿ�� �� �� �ִ�

// Ʈ��
// 1, ����Ʈ��
// 2. ��ȭ����Ʈ��
// 3. ��������Ʈ��
// 4. ��Ʈ��
// 5. �ڱ����Ž��Ʈ��


struct Node
{
	Node() {}

	vector<Node*> children;
	string data;
};

Node* CreateTree()
{
	Node* root = new Node("���ߺ�");
	{
		root->children.push_back(node1_1);
	}
	return root;
}

void PrintTree(Node* node());  

int main()
{
	Node* developeteam = CreateTree();


	return 0;
}