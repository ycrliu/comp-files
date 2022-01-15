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
using ii = pair<int, int>;

vector<ii> adj[MAXN];
int d[MAXN];
int p[MAXN];
bool vis[MAXN];

void dijkstra(int s)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[s] = 0;

    // min heap priority queue
    priority_queue<ii, vector<ii>, greater<ii>> q; // {d[v], v}
    q.push({0, s});
    while(!q.empty())
    {
        // extract-min(q)
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if(d_v != d[v])
        {
            // if d_v equals d[v], that means v has already been operated on,
            // which means that there is a min distance l[v] from s to v, and
            // d[v] == l[v].
            // otherwise, there aren't any more vertices from which we can perform
            // relaxations
            continue;
        }
        // perform relaxations
        for(ii edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

// using set (red-black tree) instead of priority_queue (heap)
void dijkstra_s(int s)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[s] = 0;
    set<pair<int, int>> q; // automatically sorted
    q.insert({0, s});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(ii edge : adj[v])
        {
            int to = edge.first, len = edge.second;
            if(d[v] + len < d[to])
            {
                q.erase({d[to], to}); // remove old values
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main()
{
    return 0;
}

