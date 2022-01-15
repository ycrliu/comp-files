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

bool f[105];
bool hdone[105]; // hdone[i] = for a cow i in the hierarchy, has its position been fixed yet

int index_of(vector<int> a, int val)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] == val)
			return i;
	return -1;
}

int main()
{
	ifstream cin("milkorder.in");
	ofstream cout("milkorder.out");
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> hie(m);
	for(int i = 0; i < m; i++)
		cin >> hie[i];
	vector<pair<int, int>> pos(k);
	for(int i = 0; i < k; i++)
		cin >> pos[i].second >> pos[i].first;
	sort(pos.begin(), pos.end());
	int last_fixed_i = -1;
	for(int i = 0; i < k; i++)
	{
		int j = index_of(hie, pos[i].second);
		if(j != -1)
		{
			f[pos[i].first] = true;
			last_fixed_i = pos[i].first;
			if(pos[i].second == 1)
			{
				cout << pos[i].first << endl;
				return 0;
			}
			hdone[j] = true;
			int p = pos[i].first - 1;
			for(j--; j >= 0 && !hdone[j]; j--, p--)
			{
				while(f[p])
					p--;
				f[p] = true;
				hdone[j] = true;
				if(hie[j] == 1)
				{
					cout << p << endl;
					return 0;
				}
			}
		}
		else
		{
			if(pos[i].second == 1)
			{
				cout << pos[i].first << endl;
				return 0;
			}
			f[pos[i].first] = true;
		}
	}
	int before_cnt = 0;
	int ind = index_of(hie, 1);
	if(ind != -1)
	{
		for(int i = ind - 1; i >= 0 && !hdone[i]; i--)
			before_cnt++;
		for(int i = 1; i <= n; i++)
		{
			if(!f[i] && i > last_fixed_i)
			{
				if(before_cnt)
					--before_cnt;
				else
				{
					cout << i << endl;
					return 0;
				}
			}
		}
	}
	else
		for(int i = 1; i <= n; i++)
			if(!f[i])
			{
				cout << i << endl;
				return 0;
			}
}
