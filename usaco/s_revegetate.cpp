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

vector<pair<int, bool>> adj[100005];
int col[100005];

bool dfs(int u, int c)
{
	bool bp = true;
	col[u] = c;
	for(auto v : adj[u])
	{
		if(col[v.first] && (col[v.first] == c) != v.second)
			return false;
		if(!col[v.first])
			bp &= dfs(v.first, v.second ? c : 3 - c);
	}
	return bp;
}

int main()
{
	ifstream cin("revegetate.in");
	ofstream cout("revegetate.out");
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		char c;
		int u, v;
		cin >> c >> u >> v;
		bool same = c == 'S';
		adj[u].push_back({v, same});
		adj[v].push_back({u, same});
	}
	int comps = 0;
	bool ok = true;
	for(int i = 1; i <= n; i++)
	{
		if(!col[i])
		{
			if(!dfs(i, 1))
			{
				ok = false;
				break;
			}
			comps++;
		}
	}
//	assert(comps < 19); // converting from decimal to bin will overflow for all but cases 1 and 11
	if(!ok)
		cout << 0;
	else
	{
		// 1 << k --> kth bit from the right is 1
		cout << 1;
		for(int i = 0; i < comps; i++)
			cout << 0;
	}
	cout << endl;
	return 0;
}

