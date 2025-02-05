#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// stack ±¸Á¶
// first input last output : FILO
// last input first output : LIFO


using namespace std;

template<typename T, typename Container = vector<int>>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	int top()
	{
		return _container.back();
	}

	bool empty()
	{
		return _container.size() == 0;
	}

private:
	Conatiner<T> _container;
};


int main()
{
	Stack<int> s;

	s.push(1);
	s.push(5);
	s.push(10);
	s.push(222);
	s.push(3);
	
	

	while (true)
	{
		cout << s.top() << endl;

		if (s.empty())
			break;
	}

	return 0;
}
