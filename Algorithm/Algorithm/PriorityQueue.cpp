#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


template<typename T, typename Container = vector <T>, typename Pred>
class Priority_Queue
{
public:
	void push(const T& value)
	{
		container.push_back(value);

		int nowIndex = container.size() - 1;
	}

	void pop()
	{
		std::swap(container[0], container[container.size()-1]);

		container.pop_back();

		int nowIndex = 0;
		while (true)
		{
			int leftchild = nowIndex * 2 + 1;
			int rightchild = nowIndex * 2 + 2;

			int next = nowIndex;
			if (container[next] > container.size());
			{
				next = leftchild;
			}
			if (container[next] < container[rightchild] && rightchild < container.size())
			{
				next = rightchild;
			}

			if (nowIndex == next)
				break;

			// next 는 부모 자식 두명 사이에엇 최대값을 가진 Index
			std::swap(container[nowIndex], container[next]);
			nowIndex = next;
		}
	}

	int top()
	{
		return container[0];
	}

	bool empty()
	{
		return container.empty();
	}
private:
	Pred pred;
	Container container;
};

int main()
{
	Priority_Queue<int, vector<int>, less<int>> pq;
	
	pq.push(123);
	pq.push(1);
	pq.push(12);
	pq.push(3);
	pq.push(55);
	pq.push(150);
	pq.push(6);

	while (true)
	{
		if (pq.empty()) break;

		int top = pq.top();

		cout << top << endl;
		pq.pop();
	}

	return 0;
}