#include <bits/stdc++.h>

using namespace std;

vector<int> adj[205];
int x[205], y[205], p[205], size;
bool vis[205];
void dfs(int u)
{
	if(vis[u])
		return;
	++size;
	vis[u] = 1;
	for(int v : adj[u])
		dfs(v);
}
int main()
{
	ifstream cin("moocast.in");
	ofstream cout("moocast.out");
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i] >> p[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i != j && (y[j]-y[i])*(y[j]-y[i]) + (x[j]-x[i])*(x[j]-x[i]) <= p[i]*p[i])
			{
				adj[i].push_back(j); // (directed edge from i to j)
			}
		}
	}
	int ans = -1;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
			ans = max(size, ans);
			size = 0;
			memset(vis, 0, sizeof vis);
		}
	}
	cout << ans << endl;
	return 0;
}

