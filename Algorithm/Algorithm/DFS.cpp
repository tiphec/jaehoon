#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

// 그래프란...
// 1. 레온하르트 오일러가 도시마다 다리를 연결하는 문제에서 생겨난 개념이다

// 코드로 그래프를 그리는 방법

// - 인접 행렬
// - 인접 리스트
// => 인접 행렬은 탐색속도는 상수이지만, 데이터를 많이 차지한다
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
	cout << here << "방문!!" << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		// 자기 자신인지 확인
		if (here == there)
			continue;

		// 인접해있는지 확인
		if (adjacent[here][there] == false)
			continue;

		// 방문이 되어있었는지 확인
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

	// 1. 6과 3이 서로 인접해있냐?
	for (auto value : adjacent_List[6])
	{
		if (value == 3)
			cout << "인접" << endl;
	}

	auto it = std::find(adjacent_List[6].begin(), adjacent_List[6].end(), 3);
	if (it != adjacent_List[6].end())
		cout << "인접" << endl;


	// 2. 4와 1이 서로 인접해있냐? (인접행렬)
	if (adjacent[4][1])
		cout << "4,1 인접" << endl;
	return 0;
}