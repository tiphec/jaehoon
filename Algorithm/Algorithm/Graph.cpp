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
vector<vector<bool>> adjecent2;

void CreateGraph_List()
{
	adjacent_List.resize(7);

	adjacent_List[0].push_back(0);
	adjacent_List[0].push_back(1);
	adjacent_List[0].push_back(2);
	   
	adjacent_List[1].push_back(1);
	adjacent_List[1].push_back(0);
	adjacent_List[1].push_back(4);
	adjacent_List[1].push_back(5);
	   
	adjacent_List[2].push_back(2);
	adjacent_List[2].push_back(0);
	adjacent_List[2].push_back(3);
	   
	adjacent_List[3].push_back(3);
	adjacent_List[3].push_back(2);
	   
	adjacent_List[4].push_back(4);
	adjacent_List[4].push_back(1);
	adjacent_List[4].push_back(6);
	   
	adjacent_List[5].push_back(5);
	adjacent_List[5].push_back(1);
	   
	adjacent_List[6].push_back(6);
	adjacent_List[6].push_back(4);
}

void CreateGraph_Matrix()
{
	adjacent.resize(7, vector<bool>(7, false));
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

int main()
{
	CreateGraph_List();

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