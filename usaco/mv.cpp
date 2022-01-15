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
using ll = long long;

string s;
vector<int> adj[100005];
int comp[100005];

void dfs(int u, int cur_comp)
{
	comp[u] = cur_comp;
	for(int v : adj[u])
		if(!comp[v] && s[v - 1] == s[u - 1])
			dfs(v, cur_comp);
}

int main()
{
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");
	int n, m;
	cin >> n >> m >> s;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int cur_comp = 1;
	for(int i = 1; i <= n; i++)
		if(!comp[i])
		{
			dfs(i, cur_comp);
			cur_comp++;
		}
	for(int i = 0; i < m; i++)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		if(comp[a] != comp[b] || s[a - 1] == c || s[b - 1] == c)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}

