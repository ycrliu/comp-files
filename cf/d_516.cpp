#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

bool grid[2005][2005];
bool vis[2005][2005];

// 0: down, 1: up, 2: right, 3: left
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int main()
{
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    r--;
    c--;
    for(int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        for(int j = 0; j < m; j++)
        {
            grid[i][j] = l[j] == '.';
        }
    }
    int ans = 0;
    vis[r][c] = true;
    // cost of path is how many x/y moves we make, not how "long" it is
    deque<tuple<int, int, int, int>> q;
    q.push_front({r, c, x, y});
    while(!q.empty())
    {
        int ci = get<0>(q.front());
        int cj = get<1>(q.front());
        int cx = get<2>(q.front());
        int cy = get<3>(q.front());
        q.pop_front();
        if(cx >= 0 && cy >= 0)
        {
            ans++;
        }
        for(int it = 0; it < 4; it++)
        {
            int ni = ci + di[it];
            int nj = cj + dj[it];
            if(ni < n && ni >= 0 && nj < m && nj >= 0 && grid[ni][nj] && !vis[ni][nj])
            {
                int nx = cx - (it == 3);
                int ny = cy - (it == 2);
                vis[ni][nj] = true;
                if(it == 0 || it == 1)
                {
                    q.push_front({ni, nj, nx, ny});
                }
                else
                {
                    q.push_back({ni, nj, nx, ny});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

