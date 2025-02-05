#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

// 서로소 집합

// 탐욕법
// : 현재 상황에서 최선의 도출된 결과를 계속 따라가는 것

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

	// user 5이 1의 길드에 소속되었다
	users[5].guildId = 1;

	// 2길드에 들어가 있는 모든 유저들을 1에 병합시키겠다
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