#include <bits/stdc++.h>

using namespace std;

int a[105][105];
bool vis[105][105];
vector<vector<pair<int, int>>> c;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int main()
{
	ifstream cin("mooyomooyo.in");
	ofstream cout("mooyomooyo.out");
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for(int j = 0; j < 10; ++j)
			a[i][j] = s[j] - '0';
	}

	while(1)
	{
		// search for components
		int cur = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < 10; ++j)
			{
				if(!vis[i][j] && a[i][j])
				{
					c.push_back(vector<pair<int, int>>());
					
					c[cur].push_back({i, j});
					vis[i][j] = 1;

					queue<pair<int, int>> q;
					q.push({i, j});
					while(!q.empty())
					{
						pair<int, int> p = q.front();
						q.pop();
						for(int k = 0; k < 4; ++k)
						{
							int ni = p.first + dx[k], nj = p.second + dy[k];
							if(~ni && ni < n && ~nj && nj < 10 && a[ni][nj] == a[i][j] && !vis[ni][nj])
							{
								q.push({ni, nj});
								c[cur].push_back({ni, nj});
								vis[ni][nj] = 1;
							}
						}
					}
					// new component
					++cur;
				}
			}
		}

		// delete components of adequate size
		bool ok = 0;
		for(int i = 0; i < c.size(); ++i)
		{
			if(c[i].size() >= k)
			{
				ok = 1;
				for(pair<int, int> p : c[i])
				{
					a[p.first][p.second] = 0;
				}
			}
		}

		if(!ok)
		{
			break;
		}

		// apply gravity
		for(int i = 0; i < 10; ++i)
		{
			vector<int> temp;
			int zeroes = 0;
			for(int j = 0; j < n; ++j)
			{
				if(a[j][i])
					temp.push_back(a[j][i]);
				else
					++zeroes;
			}
			int j = 0, x = 0;
			for(; j < n && j < zeroes; ++j)
				a[j][i] = 0;
			for(; j < n && x < temp.size(); ++j, ++x)
				a[j][i] = temp[x];
		}

		c.clear();
		memset(vis, 0, sizeof vis);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 10; ++j)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}

