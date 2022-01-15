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
#include <cassert>

using namespace std;
using ll = long long;

set<int> readings;

void recur(int day, int t1, int t2, vector<int> sz1, vector<int> sz2)
{
	if(day >= 4)
	{
		readings.insert(t1);
	}
	else if(day == 1 || day == 3) // Wednesday/Friday
	{
		for(int i = 0; i < sz2.size(); i++)
		{
//			vector<int> sz1c = sz1, sz2c = sz2;
//			sz2c.erase(sz2c.begin() + i);
//			sz1c.push_back(sz2[i]);
			int sz = sz2[i];
			sz2.erase(sz2.begin() + i);
			int addi = sz1.size();
			sz1.push_back(sz);
//			recur(day + 1, t1 + sz2[i], t2 - sz2[i], sz1c, sz2c);
			recur(day + 1, t1 + sz, t2 - sz, sz1, sz2);
			sz2.insert(sz2.begin() + i, sz);
			sz1.erase(sz1.begin() + addi);
		}
	}
	else // Tuesday/Thursday
	{
		for(int i = 0; i < sz1.size(); i++)
		{
			vector<int> sz1c = sz1, sz2c = sz2;
			sz1c.erase(sz1c.begin() + i);
			sz2c.push_back(sz1[i]);
			recur(day + 1, t1 - sz1[i], t2 + sz1[i], sz1c, sz2c);
		}
	}
}

int main()
{
	ifstream cin("backforth.in");
	ofstream cout("backforth.out");
	vector<int> sz1(10), sz2(10);
	for(int i = 0; i < 10; i++)
		cin >> sz1[i];
	for(int i = 0; i < 10; i++)
		cin >> sz2[i];
	recur(0, 1000, 1000, sz1, sz2);
	cout << readings.size() << endl;
	return 0;
}

