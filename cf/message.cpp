#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<string, int> index_of;
int cost[100005];
int cheapest_in_group[100005];
int group_of[100005];

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++)
	{
		string word;
		cin >> word;
		index_of[word] = i;
	}
	for(int i = 1; i <= n; i++)
		cin >> cost[i];
	for(int i = 0; i < n; i++)
		cheapest_in_group[i] = INT_MAX;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			int ind;
			cin >> ind;
			cheapest_in_group[i] = min(cost[ind], cheapest_in_group[i]);
			group_of[ind] = i;
		}
	}
	ll total_cost = 0;
	for(int i = 0; i < m; i++)
	{
		string word;
		cin >> word;
		total_cost += cheapest_in_group[group_of[index_of[word]]];
	}
	cout << total_cost << endl;
	return 0;
}

