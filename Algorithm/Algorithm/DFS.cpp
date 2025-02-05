#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

// �׷�����...
// 1. �����ϸ�Ʈ ���Ϸ��� ���ø��� �ٸ��� �����ϴ� �������� ���ܳ� �����̴�

// �ڵ�� �׷����� �׸��� ���

// - ���� ���
// - ���� ����Ʈ
// => ���� ����� Ž���ӵ��� ���������, �����͸� ���� �����Ѵ�
vector<vector<int>> adjacent_List;
vector<vector<bool>> adjacent;
vector<bool> visited;

void CreateGraph_Matrix()
{
	adjacent.resize(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);
	// 7 x 7
	//    0   1   2   3   4   5   6
	// 0  T   T   T   F   F   F   F
	// 1  T   T   F   F   T   T   F
	// 2  T   F   T   T   F   F   F
	// 3  F   F   T   T   F   F   F
	// 4  F   T   F   F   T   F   T
	// 5  F   T   F   F   F   T   F
	// 6  F   F   F   F   T   F   T

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;
	adjacent[1][5] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;
	adjacent[4][6] = true;

	adjacent[5][1] = true;
	adjacent[5][5] = true;

	adjacent[6][4] = true;
	adjacent[6][6] = true;
}



void DFS(int here)
{
	visited[here] = true;
	cout << here << "�湮!!" << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		// �ڱ� �ڽ����� Ȯ��
		if (here == there)
			continue;

		// �������ִ��� Ȯ��
		if (adjacent[here][there] == false)
			continue;

		// �湮�� �Ǿ��־����� Ȯ��
		if (visited[there] == true)
			continue;

		DFS(there);
	}
}

void DDFS_ALL(int start)
{
	int count = 0;
	for (int i = 0; i < adjacent.size(); i++);
	{
		count++;
		DFS(i);
	}

	cout << count << endl;
}

int main()
{
	CreateGraph_Matrix();
	DFS(0);

	// 1. 6�� 3�� ���� �������ֳ�?
	for (auto value : adjacent_List[6])
	{
		if (value == 3)
			cout << "����" << endl;
	}

	auto it = std::find(adjacent_List[6].begin(), adjacent_List[6].end(), 3);
	if (it != adjacent_List[6].end())
		cout << "����" << endl;


	// 2. 4�� 1�� ���� �������ֳ�? (�������)
	if (adjacent[4][1])
		cout << "4,1 ����" << endl;
	return 0;
}