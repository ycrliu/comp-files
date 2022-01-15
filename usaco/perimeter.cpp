#include <bits/stdc++.h>

using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
	ifstream cin("perimeter.in");
	ofstream cout("perimeter.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	int maxarea = -1;
	vector<pair<int, int>> comps;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(!vis[i][j] && a[i][j] == '#')
			{
				vis[i][j] = 1;
				int area = 1, perim = 0;
				
				queue<pair<int, int>> q;
				q.push({i, j});
				while(!q.empty())
				{
					pair<int, int> p = q.front();
					q.pop();
					for(int k = 0; k < 4; ++k)
					{
						int ni = p.first + dx[k], nj = p.second + dy[k];
						if(~ni && ni < n && ~nj && nj < n)
						{
							if(!vis[ni][nj] && a[ni][nj] == '#')
							{
								vis[ni][nj] = 1;
								q.push({ni, nj});
								++area;
							}
							if(a[ni][nj] == '.')
								++perim;
						}
						else
							++perim;
					}
				}
				maxarea = max(area, maxarea);
				comps.push_back({area, perim});
			}
		}
	}
	sort(comps.begin(), comps.end());
	for(int i = 0; i < comps.size(); ++i)
		if(comps[i].first == maxarea)
		{
			cout << comps[i].first << " " << comps[i].second << endl;
			break;
		}
	return 0;
}

