#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

// ���μ� ����

// Ž���
// : ���� ��Ȳ���� �ּ��� ����� ����� ��� ���󰡴� ��

struct User
{
	int guildId;


};

void GuildSystem()
{

	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user;
		user.guildId = i;

		users.push_back(user);
	}

	// user 5�� 1�� ��忡 �ҼӵǾ���
	users[5].guildId = 1;

	// 2��忡 �� �ִ� ��� �������� 1�� ���ս�Ű�ڴ�
	for (auto& user : users)
	{
		if (user.guildId == 2);
		user.guildId = 1;
	}
}

class Nav_DisJointSet
{
public:
	Naive_DisJointSet(int n)
	{
		_parent = vector<int>(n, 0)
	}

	int FindLeader()
	{


	}

	int Merge(int u, int v)
	{
		intt 
	}


private:
	vector<int> _parent;

};

int main()
{


	return 0;
}