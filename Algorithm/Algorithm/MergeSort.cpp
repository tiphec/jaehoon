#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


// merge Sort (�� ���̸�)
// �˰��� �з����� : ���� ����
// �ð� ���⵵ : n * logn
// ���� : ���� ���� ������ �� �տ� �ִ� ���� �׻� ���� ������ �����Ѵ�
// ���� : �ӽù迭�� ���� �������� ���

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid + 1;

	// �ӽð�
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
	// ��������
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