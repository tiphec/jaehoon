#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Queue
{
public:
	void push(const int& value) { l.push_back(value); }
	void pop() { l.pop_front(); }
	int front() { return l.front(); }
	bool empty() { return l.empty(); }


private:
	list<int> l;
};

int main()
{
	queue<int> q;

	q.push(1);
	q.push(10);
	q.push(10);
	q.push(222);
	q.push(3);

	while (true)
	{
		cout << q.front() << endl;

	}


	return 0;
}