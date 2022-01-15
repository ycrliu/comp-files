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
#include <cassert>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

bool grid[1005][1005];
bool vis[1005][1005];
int d[1005][1005];
int p[1005][1005];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, -1, 1};
char dc[] = {'D', 'U', 'L', 'R'};

int main()
{
    int n, m;
    cin >> n >> m;
    int si = 0;
    int sj = 0;
    int ei = 0;
    int ej = 0;
    for(int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        for(int j = 0; j < m; j++)
        {
            if(l[j] == 'A')
            {
                si = i;
                sj = j;
            }
            else if(l[j] == 'B')
            {
                ei = i;
                ej = j;
            }
            grid[i][j] = l[j] == '.' || l[j] == 'A' || l[j] == 'B';
        }
    }
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    memset(d, INF, sizeof(d));
    d[si][sj] = 0;
    while(!q.empty())
    {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        for(int it = 0; it < 4; it++)
        {
            int ni = ci + di[it];
            int nj = cj + dj[it];
            if(ni < n && ni >= 0 && nj < m && nj >= 0 && !vis[ni][nj] && grid[ni][nj])
            {
                d[ni][nj] = min(1 + d[ci][cj], d[ni][nj]);
                p[ni][nj] = it;
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
    if(vis[ei][ej])
    {
        cout << "YES\n" << d[ei][ej] << endl;
        string dir = "";
        while(ei != si || ej != sj)
        {
            dir += dc[p[ei][ej]];
            int oi = -1;
            switch(p[ei][ej])
            {
                case 0:
                    oi = 1;
                    break;
                case 1:
                    oi = 0;
                    break;
                case 2:
                    oi = 3;
                    break;
                default:
                    oi = 2;
                    break;
            }
            ei += di[oi];
            ej += dj[oi];
        }
        reverse(dir.begin(), dir.end());
        cout << dir << endl;
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}

