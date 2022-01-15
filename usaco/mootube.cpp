#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5005];
int n, rel[5005][5005];
int currel = INT_MAX, cnt;
bool vis[5005];
void dfs(int u, int k, int start)
{
	vis[u] = 1;

	int tempmin = currel;
	for(int v : adj[u])
	{
		if(rel[u][v] && !vis[v])
		{
//			cout << "rel " << u << " to " << i << endl;

			currel = min(rel[u][v], currel);
//			cout << "current rel " << currel << endl;
			if(currel >= k)
			{
				++cnt;
			}
			dfs(v, k, start);
			
			currel = tempmin;
			// if backtracking, reset back to the previous minimum relevance (on the current path)

			if(u == start) // if back at the starting vertex, reset the current minimum relevance to infinity (starting a new path)
			{
				currel = INT_MAX;
			}
		}
	}
}
int main()
{
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");
	int q;
	cin >> n >> q;
	
	for(int i = 0; i < n - 1; ++i)
	{
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back(q);
		adj[q].push_back(p);
		rel[p][q] = r;
		rel[q][p] = r;
	}
	while(q--)
	{
		int k, v;
		cin >> k >> v;
		dfs(v, k, v);
		cout << cnt << endl;

		memset(vis, 0, sizeof vis);
		cnt = 0;
		currel = INT_MAX;
	}
	return 0;
}

