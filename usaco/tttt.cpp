#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;

char g[3][3];

int main()
{
	ifstream cin("tttt.in");
	ofstream cout("tttt.out");

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> g[i][j];
	int singles = 0;

	// Singles
	int rowcount = 0;
	int colcount = 0;
	set<char> winners; // keep track of which cows have already won
	for(int i = 0; i < 3; i++)
	{
		bool ok = true;
		for(int j = 1; j < 3; j++)
			if(g[i][j] != g[i][0])
				ok = false;
		if(ok && !winners.count(g[i][0]))
		{
			rowcount++;
			winners.insert(g[i][0]);
		}
	}
	for(int i = 0; i < 3; i++)
	{
		bool ok = true;
		for(int j = 1; j < 3; j++)
			if(g[j][i] != g[0][i])
				ok = false;
		if(ok && !winners.count(g[0][i]))
		{
			colcount++;
			winners.insert(g[0][i]);
		}
	}
	singles += rowcount;
	singles += colcount;

	bool ok = true;
	for(int i = 1; i < 3; i++)
		if(g[i][i] != g[0][0])
			ok = false;
	if(ok && !winners.count(g[0][0]))
	{
		singles++;
		winners.insert(g[0][0]);
	}
	ok = true;
	for(int i = 1; i < 3; i++)
		if(g[0][2] != g[i][2 - i])
			ok = false;
	if(ok && !winners.count(g[0][2]))
	{
		singles++;
		winners.insert(g[0][2]);
	}

	// Doubles
	int doubles = 0;
	set<pair<char, char>> winners1; // lexicographically sorted
	for(int i = 0; i < 3; i++)
	{
		set<char> team;
		for(int j = 0; j < 3; j++)
			team.insert(g[i][j]);
		pair<char, char> chk = {*team.begin(), *(++team.begin())};
		if(team.size() == 2 && !winners1.count(chk))
		{
			doubles++;
			winners1.insert(chk);
		}
	}
	for(int i = 0; i < 3; i++)
	{
		set<char> team;
		for(int j = 0; j < 3; j++)
			team.insert(g[j][i]);
		pair<char, char> chk = {*team.begin(), *(++team.begin())};
		if(team.size() == 2 && !winners1.count(chk))
		{
			doubles++;
			winners1.insert(chk);
		}
	}
	set<char> team;
	for(int i = 0; i < 3; i++)
		team.insert(g[i][i]);
	pair<char, char> chk = {*team.begin(), *(++team.begin())};
	if(team.size() == 2 && !winners1.count(chk))
	{
		doubles++;
		winners1.insert(chk);
	}
	team.clear();
	for(int i = 0; i < 3; i++)
		team.insert(g[i][2 - i]);
	chk = {*team.begin(), *(++team.begin())};
	if(team.size() == 2 && !winners1.count(chk))
	{
		doubles++;
		winners1.insert(chk);
	}

	cout << singles << endl << doubles << endl;
	return 0;
}

