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

int n, m;
int maze[1005][1005];
int dist[1005][1005][2]; // dist[x][y][smelly?]

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool can_go(int i, int j, bool f)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if(maze[i][j] == 0)
    {
        return false;
    }
    if(maze[i][j] == 3)
    {
        return f;
    }
    return true;
}

int main()
{
    ifstream cin("dream.in");
    ofstream cout("dream.out");
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    
    memset(dist, INF, sizeof(dist));
    set<pair<int, tuple<int, int, bool>>> q;
    q.insert({0, {0, 0, false}});
    dist[0][0][0] = 0;

    while(!q.empty())
    {
        int d = q.begin()->first;
        int ci = get<0>(q.begin()->second);
        int cj = get<1>(q.begin()->second);
        bool f = get<2>(q.begin()->second);
        q.erase(q.begin());
        // it isn't guaranteed that d always equals dist[ci][cj][f]; the dp
        // array could have been updated before q.begin() is analyzed
        if(ci == n - 1 && cj == m - 1)
        {
            cout << dist[ci][cj][f] << endl;
            return 0;
        }
        for(int it = 0; it < 4; it++)
        {
            int ni = ci + di[it];
            int nj = cj + dj[it];
            int nd = 1 + d;
            int nf = f;
            if(!can_go(ni, nj, nf))
            {
                continue;
            }
            if(maze[ni][nj] == 2)
            {
                nf = 1;
            }
            else if(maze[ni][nj] == 4)
            {
                // be careful not to change ci, cj, f, or d; we need these variables
                // to remain constant while iterating it from 0 to 4
                // use nf instead of f here
                while(can_go(ni + di[it], nj + dj[it], nf) && maze[ni][nj] == 4)
                {
                    nd++;
                    ni += di[it];
                    nj += dj[it];
                    nf = 0;
                }
                nf = maze[ni][nj] == 2;
            }

            if(nd < dist[ni][nj][nf])
            {
                q.erase({nd, {ni, nj, nf}});
                dist[ni][nj][nf] = nd;
                q.insert({nd, {ni, nj, nf}});
            }
        }
    }
    cout << "-1\n";
    return 0;
}

