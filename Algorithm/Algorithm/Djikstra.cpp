#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


vector<vector<int>> adjacent;

struct Vectex
{
	Vectex() {}
	Vectex(int num, int g) : vertexNum(num), g(g) {}

	bool operator<(const Vertex& other) const
	{
		return g < other.g;
	}

	bool operator>(const Vertex& other) const
	{
		return g > other.g;
	}

	int vertexNum = 0;
	int g = 0; // 가중치    
};


// 다익스트라 (시작점)
// -BFS
// 우선순위 큐 사용
vector<bool> discovered;
vector<int> parent;
vector<int> best; // 해당 노드의 최소 가중치를 기입 

void Djikstra(int start)
{
	parent = vector<int>(adjacent.size(), -1);
	vector<int> best(adjacent.size(), INT_MAX);
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>>;

	Vertex startV = Vertex(start, 0);
	best[start] = 0;
	pq.push(startV);
	parent[startV.vertesNum = startV.vertexNum;

	while (true)
	{
		if(pq.emptry == true) break;

		Vertex hereV = pq.top();
		pq.pop();

		for (int there = 0; there < adjacent.size() - 1; there++)
		{
			int here = hereV.vertexNum;
			// here 와 같은곳
			if (hereV.vertexNum == there)
				continue;

			// 지금 나의 위치의 best값 + there 까지의 간선의 길이
			int nowCost = best[here] + adjacent[here][there];
		}
	}
}


// 인접행렬
void CreateGraph_Matrix()
{
	adjacent.resize(7, vector<int>(7, -1));
	
	// 7 x 7
	//    0   1   2   3   4   5   6
	// 0  0   T   T   F   F   F   F
	// 1  T   0   F   F   T   T   F
	// 2  T   F   0   T   F   F   F
	// 3  F   F   T   0   F   F   F
	// 4  F   T   F   F   0   F   T
	// 5  F   T   F   F   F   0   F
	// 6  F   F   F   F   T   F   0

	adjacent[0][0] = 0;
	adjacent[0][1] = 10;
	adjacent[0][2] = 3;

	adjacent[1][0] = 10;
	adjacent[1][1] = 0;
	adjacent[1][4] = 1;
	adjacent[1][5] = 4;

	adjacent[2][0] = 3;
	adjacent[2][2] = 0;
	adjacent[2][3] = 2;

	adjacent[3][2] = 2;
	adjacent[3][3] = 0;
	adjacent[3][4] = 2;

	adjacent[4][1] = 1;
	adjacent[4][4] = 0;
	adjacent[4][6] = 7;
	adjacent[4][3] = 2;

	adjacent[5][1] = 4;
	adjacent[5][5] = 0;

	adjacent[6][4] = 7;
	adjacent[6][6] = 0;
}


int main()
{
	CreateGraph_Matrix();

	return 0;
}