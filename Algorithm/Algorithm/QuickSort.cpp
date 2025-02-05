#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

	using namespace std;

int Partition(vector<int>&& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex)
			break;

		while (lowIndex <= right && pivot >= v[lowIndex])
		{
			lowIndex++;
		}

		while (highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex--;
		}

		if (lowIndex < highIndex)
			std::swap(v[lowIndex], v[highIndex]);
	}

	std::swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// 기저사항 : 제일 마지막 예외
	if (left > right)
		return;

	int pivotIndex = Partition(v,left, right); // 자기 위치 찾기

	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
}

int main()
{
	vector<int> v = { 14, 5, 3, 12, 1, 17, 50 };

	// QuickSort(v, 0, v.size() - 1);

	return 0;
}