#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>


using namespace std;

// 선형자료구조
// vector
// list
// queue
// stack

// 비선형자료구조
// graph
// tree(map)
// unordered_map (hash_table)
// map

// tree
// 1. 계층구조를 설명하기 좋은 구조
// - 부모노드와 자식노드로 이루어져있는 구조
// => 모든 트리에는 최상위 부모노드가 단 하나 있다. (Root 노드)
// => 모든 트리에는 여러명의 최하위노드가 있다. (leaf 노드)
// 2. 트리는 잘라도 트리다.
// => 서브트리가 존재한다
// => 재귀적으로 자식을 타고 들어갈 수 있다

// 트리
// 1, 이진트리
// 2. 포화이진트리
// 3. 완전이진트리
// 4. 힙트리
// 5. 자기균형탐색트리


struct Node
{
	Node() {}

	vector<Node*> children;
	string data;
};

Node* CreateTree()
{
	Node* root = new Node("개발부");
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