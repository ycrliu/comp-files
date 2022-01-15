#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool a[2005][2005];

int main()
{
#ifndef HOME
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
#endif
	int n;
	string s;
	cin >> n >> s;
	int x = 1001, y = 1001;
	for(int i = 0; i < n; ++i)
	{
		int dx = 0, dy = 0;
		if(s[i] == 'N')
			dx = -1;
		if(s[i] == 'S')
			dx = 1;
		if(s[i] == 'E')
			dy = 1;
		if(s[i] == 'W')
			dy = -1;
		for(int j = 0; j < 2; ++j)
		{
			a[x][y] = 1;
			x += dx;
			y += dy;
		}
	}
	int cnt = 0;
	for(int i = 0; i < 2005; ++i)
	{
		for(int j = 0; j < 2005; ++j)
		{
			if(!a[i][j])
			{
				++cnt;
				a[i][j] = 1;
				queue<ii> q;
				q.push({i, j});
				while(!q.empty())
				{
					ii pt = q.front();
					q.pop();
					for(int k = 0; k < 4; ++k)
					{
						int ni = pt.fi + dx[k], nj = pt.se + dy[k];
						if(ni < 2005 && ~ni && nj < 2005 && ~nj && !a[ni][nj])
						{
							a[ni][nj] = 1;
							q.push({ni, nj});
						}
					}
				}
			}
		}
	}
	cout << cnt - 1;
	return 0;
}

