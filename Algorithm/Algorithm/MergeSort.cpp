#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


// merge Sort (폰 노이만)
// 알고리즘 패러다임 : 분할 정복
// 시간 복잡도 : n * logn
// 장점 : 같은 값을 가졌을 때 앞에 있던 값이 항상 같은 순서를 유지한다
// 단점 : 임시배열을 만들어서 복사비용이 든다

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid + 1;

	// 임시값
	vector<int>temp;

	while (true)
	{
		if (leftIndex > mid || rightIndex > right)
		{
			break;
		}
		
		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);

			leftIndex++;
		}
		else
		{
			temp.push_back(v.[rightIndex]);
			rightIndex++;
		}
	}

	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}



void MergeSort(vector<int>& v, int left, int right)
{
	// 기저사항
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	//divide
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	//Conquer
	MergeResult(v, left, mid, right);

}

int main()
{


	vector<int> v = { 3,4,5,2,3,1234,42,31,50,55 };
	
	MergeSort(v, 0, v.size() - 1);

	return 0;
}