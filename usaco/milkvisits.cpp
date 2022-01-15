#include <bits/stdc++.h>

using namespace std;

char type[100005];
vector<int> adj[100005];
int comp[100005];
void dfs(int u, char c, int cur)
{
	if(comp[u])
		return;
	comp[u] = cur;
	for(int v : adj[u])
		if(type[v] == c)
			dfs(v, c, cur);
}
int main()
{
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> type[i];
	for(int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int it = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(!comp[i])
		{
			dfs(i, type[i], it);
			++it;
		}
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		if(comp[a] ^ comp[b] || type[a] == c || type[b] == c)
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
	return 0;
}

