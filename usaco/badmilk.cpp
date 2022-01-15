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

const int MAX_N = 100000;

int drink[1005][3];
int sick[55][2];

int main()
{
	ifstream cin("badmilk.in");
	ofstream cout("badmilk.out");

	int n, m, d, s;
	cin >> n >> m >> d >> s;
	for(int i = 0; i < d; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> drink[i][j];
		}
	}
	for(int i = 0; i < s; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cin >> sick[i][j];
		}
	}
	
	int ans = 0;
	// check for each milk if every person who became sick during the party
	// drank it before being sick; then, among the "bad milks," choose the
	// milk with the most drinkers
	for(int milk = 1; milk <= 50; milk++)
	{
		bool milkWorks = true;
		for(int i = 0; i < s; i++)
		{
			bool drankBeforeSick = false;
			// check records of sick person "i""
			for(int j = 0; j < d; j++)
			{
				if(sick[i][0] == drink[j][0] && milk == drink[j][1]
						&& drink[j][2] < sick[i][1])
				{
					drankBeforeSick = true;
					break;
				}
			}
			if(!drankBeforeSick)
			{
				milkWorks = false;
				break;
			}
		}
		if(milkWorks)
		{
			set<int> drinkers;
			for(int i = 0; i < d; i++)
			{
				if(drink[i][1] == milk)
				{
					drinkers.insert(drink[i][0]);
				}
			}
			ans = max((int)(drinkers.size()), ans);
		}
	}
	cout << ans << endl;
	return 0;
}

