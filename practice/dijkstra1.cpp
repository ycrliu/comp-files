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

vector<pair<int, int>> adj[MAXN]; // adj[u]: edge from u to v with cost len
int d[MAXN];
int p[MAXN];
bool vis[MAXN];

void dijkstra(int s)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[s] = 0;
    for(int i = 0; i < n; i++)
    {
        int v = -1;
        // greedy: pick the vertex v with minimal d[v]
        // this requires a lot of time to do
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && (v == -1 || d[j] < d[v]))
            {
                v = j;
            }
        }
        if(d[v] == INF)
        {
            break;
        }
        vis[v] = true;
        // perform relaxations on all outgoing edges from v
        for(pair<int, int> edge : adj[v])
        {
            int to = edge.first, len = edge.second;
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

// restore path from s to e
vector<int> restore_path(int s, int e)
{
    vector<int> path;
    for(int v = e; v != s; v = p[v])
    {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    return 0;
}

