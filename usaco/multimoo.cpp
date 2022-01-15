// check neighboring pairs
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

int n, g[255][255];
bool vis[255][255];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

bool e(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}

int main()
{
	ifstream cin("multimoo.in");
	ofstream cout("multimoo.out");
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> g[i][j];
	int a1 = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!vis[i][j])
			{
				int sz = 1;
				vis[i][j] = true;
				queue<pair<int, int>> q;
				q.push({i, j});
				while(!q.empty())
				{
					auto p = q.front();
					q.pop();
					for(int k = 0; k < 4; k++)
					{
						int ni = p.first + di[k], nj = p.second + dj[k];
						if(e(ni, nj) && !vis[ni][nj] && g[ni][nj] == g[i][j])
						{
							q.push({ni, nj});
							vis[ni][nj] = true;
							sz++;
						}
					}
				}
				a1 = max(sz, a1);
			}
		}
	}
	memset(vis, 0, sizeof vis);
	int a2 = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!vis[i][j] && g[i][j] != g[i - 1][j])
			{
				int sz = 1;
				vis[i][j] = true;
				queue<pair<int, int>> q;
				q.push({i, j});
				while(!q.empty())
				{
					auto p = q.front();
					q.pop();
					for(int k = 0; k < 4; k++)
					{
						int ni = p.first + di[k], nj = p.second + dj[k];
						if(e(ni, nj) && !vis[ni][nj] && (g[ni][nj] == g[i][j] || g[ni][nj] == g[i - 1][j]))
						{
							q.push({ni, nj});
							vis[ni][nj] = true;
							sz++;
						}
					}
				}
				a2 = max(sz, a2);
				// special case if there's only two distinct IDs on the board (otherwise the bfs will take n^4 time)
				if(a2 == n * n)
					goto end;
				memset(vis, 0, sizeof vis);
			}
		}
	}
	end: cout << a1 << endl << a2 << endl;
	return 0;
}

