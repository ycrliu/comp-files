#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> sw[105][105];
bool lit[105][105], vis[105][105];
int n;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void dfs(int i, int j)
{
	if(vis[i][j])
		return;
	vis[i][j] = 1;
	for(pair<int, int> s : sw[i][j])
	{
		lit[s.first][s.second] = 1;
		bool hasvn = 0;
		for(int k = 0; k < 4; ++k)
		{
			int ni = s.first + dx[k], nj = s.second + dy[k];
			if(ni && ni <= n && nj && nj <= n && vis[ni][nj])
				hasvn = 1;
		}
		if(hasvn)
			dfs(s.first, s.second);
	}
	for(int k = 0; k < 4; ++k)
	{
		int ni = i + dx[k], nj = j + dy[k];
		if(ni && ni <= n && nj && nj <= n && !vis[ni][nj] && lit[ni][nj])
			dfs(ni, nj);
	}
}
int main()
{
//	ifstream cin("lightson.in");
//	ofstream cout("lightson.out");
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		sw[x][y].push_back({a, b});
	}
	dfs(1, 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			ans += lit[i][j];
	cout << ans << endl;
	return 0;
}

