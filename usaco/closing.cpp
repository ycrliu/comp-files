#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;

int n;
bool vis[MAXN];
vector<int> adj[MAXN];
bool closed[MAXN];
void dfs(int u)
{
	vis[u] = 1;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v);
}
bool connected()
{
	for(int i = 1; i <= n; ++i)
		if(!vis[i] && !closed[i])
			return false;
	return true;
}
int main()
{
	ifstream cin("closing.in");
	ofstream cout("closing.out");

	int m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	cout << (connected() ? "YES" : "NO") << endl;

	for(int i = 0; i < n - 1; ++i)
	{
		memset(vis, 0, sizeof vis);
		int c;
		cin >> c;
		adj[c].clear();
		closed[c] = 1;
		
		int node = 1;
		for(; node <= n; ++node)
			if(!closed[node])
				break;

		dfs(node);
		cout << (connected() ? "YES" : "NO") << endl;
	}
	int f;
	cin >> f;

	return 0;
}

