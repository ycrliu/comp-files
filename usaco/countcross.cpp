#include <bits/stdc++.h>

using namespace std;

int n;
bool adj[105][105][4]; // 0-up, 1-right, 2-down, 3-left
int f1[] = {-1, 0, 1, 0};
int f2[] = {0, 1, 0, -1};
pair<int, int> cows[105];
int comp[105][105];
void dfs(int i, int j, int cur)
{
	comp[i][j] = cur;
	for(int k = 0; k < 4; ++k)
		if(adj[i][j][k])
		{
			int ni = i + f1[k], nj = j + f2[k];
			if(ni >= 1 && ni <= n && nj >= 1 && nj <= n && !comp[ni][nj])
				dfs(ni, nj, cur);
		}
}
int main()
{
	ifstream cin("countcross.in");
	ofstream cout("countcross.out");

	int k, r;
	cin >> n >> k >> r;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(i - 1 >= 1)
				adj[i][j][0] = 1;
			if(j + 1 <= n)
				adj[i][j][1] = 1;
			if(i + 1 <= n)
				adj[i][j][2] = 1;
			if(j - 1 >= 1)
				adj[i][j][3] = 1;
		}
	for(int i = 0; i < r; ++i)
	{
		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		int dx = c1 - c, dy = r1 - r;
		if(dy == -1)
		{
			adj[r][c][0] = 0;
			if(r - 1) adj[r - 1][c][2] = 0;
		}
		if(dx == 1)
		{
			adj[r][c][1] = 0;
			if(c + 1 <= n) adj[r][c + 1][3] = 0;
		}
		if(dy == 1)
		{
			adj[r][c][2] = 0;
			if(r + 1 <= n) adj[r + 1][c][0] = 0;
		}
		if(dx == -1)
		{
			adj[r][c][3] = 0;
			if(c - 1) adj[r][c - 1][1] = 0;
		}
	}
	
	int cur = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!comp[i][j])
			{
				dfs(i, j, cur);
				++cur;
			}

	for(int i = 0; i < k; ++i)
		cin >> cows[i].first >> cows[i].second;
	int pairs = 0;
	for(int i = 0; i < k; ++i)
		for(int j = 0; j < k; ++j)
			if(i != j && comp[cows[i].first][cows[i].second] != comp[cows[j].first][cows[j].second])
				++pairs;
	cout << pairs / 2 << endl;

	return 0;
}

