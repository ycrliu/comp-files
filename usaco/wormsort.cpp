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

int n, p[100005], comp[100005];
vector<pair<int, ll>> adj[100005];

void dfs(int u, int col, ll min_w)
{
	if(comp[u])
		return;
	comp[u] = col;
	for(auto v : adj[u])
		if(v.second >= min_w)
			dfs(v.first, col, min_w);
}

bool valid(ll min_w)
{
	memset(comp, 0, sizeof comp);
	int cur_comp = 1;
	for(int i = 1; i <= n; i++)
		if(!comp[i])
		{
			dfs(i, cur_comp, min_w); // divide graph into connected components/label each node
			cur_comp++;
		}
	for(int i = 1; i <= n; i++)
	{
		if(comp[i] != comp[p[i]]) // can't swap
			return false;
	}
	return true;
}

int main()
{
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	ll lo = 0, hi = 1e9 + 5, ans = -1;
	while(lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		if(valid(mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << (ans == 1000000005 ? -1 : ans) << endl;
	return 0;
}

