/*
ID: robertl8
LANG: C++11
TASK: castle
*/
#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[55][55], wall[55][55][55]; //0-west 1-north 2-east 3-south
int sizes[55][55]; // sizes[i][j] holds the size of the room that the module i,j is in
int comp[55][55]; // id for current room

int main()
{
	ifstream cin("castle.in");
	ofstream cout("castle.out");
	
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int ai;
			cin >> ai;
			if(ai >= 8)
			{
				ai -= 8;
				wall[i][j][3] = 1;
			}
			if(ai >= 4)
			{
				ai -= 4;
				wall[i][j][2] = 1;
			}
			if(ai >= 2)
			{
				ai -= 2;
				wall[i][j][1] = 1;
			}
			if(ai >= 1)
			{
				ai -= 1;
				wall[i][j][0] = 1;
			}
		}
	}

	int numrooms = 0, largestroom = -1, cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(!vis[i][j])
			{
				vector<pair<int, int>> visitedpoints;
				++cnt;
				++numrooms;
				int size = 1;
				vis[i][j] = 1;
				queue<pair<int, int>> q;
				q.push({i, j});
				visitedpoints.push_back({i, j});
				while(!q.empty())
				{
					pair<int, int> p = q.front();
					int pi = p.first, pj = p.second;
					q.pop();
					for(int k = 0; k < 4; ++k)
					{
						if(wall[pi][pj][0] && dx[k] < 0) continue;
						if(wall[pi][pj][1] && dy[k] < 0) continue;
						if(wall[pi][pj][2] && dx[k] > 0) continue;
						if(wall[pi][pj][3] && dy[k] > 0) continue;

						int i1 = pi + dy[k], j1 = pj + dx[k];
						if(~i1 && i1 < n && ~j1 && j1 < m && !vis[i1][j1])
						{
							vis[i1][j1] = 1;
							++size;
							q.push({i1, j1});
							visitedpoints.push_back({i1, j1});
						}
					}
				}
				largestroom = max(size, largestroom);
				for(int k = 0; k < visitedpoints.size(); ++k)
				{
					sizes[visitedpoints[k].first][visitedpoints[k].second] = size;
					comp[visitedpoints[k].first][visitedpoints[k].second] = cnt;
				}
			}
		}
	}

	int maxcombsize = 0, besti = 0, bestj = 0;
	char dir = '\0';
	for(int j = 0; j < m; ++j)
	{
		for(int i = n - 1; ~i; --i)
		{
			
			if(comp[i][j] ^ comp[i - 1][j] && sizes[i][j] + sizes[i - 1][j] > maxcombsize)
			{
				maxcombsize = sizes[i][j] + sizes[i - 1][j];
				besti = i + 1;
				bestj = j + 1;
				dir = 'N';
			}
			if(j + 1 < m && comp[i][j] ^ comp[i][j + 1] && sizes[i][j] + sizes[i][j + 1] > maxcombsize)
			{
				maxcombsize = sizes[i][j] + sizes[i][j + 1];
				besti = i + 1;
				bestj = j + 1;
				dir = 'E';
			}
		}
	}

	cout << numrooms << endl << largestroom << endl << maxcombsize << endl << besti << " " << bestj << " " << dir << endl;
	return 0;
}

