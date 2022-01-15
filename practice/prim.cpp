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

int n;
bool vis[MAXN];
int d[MAXN]; // cutset edge: distance to an arbitrary already selected vertex
int p[MAXN];
vector<pair<int, int>> adj[MAXN];

// given a graph G=(V,E), this function produces an MST
// - let r be some vertex in V
void prim(int src)
{
    int tot = 0;
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    set<pair<int, int>> q;
    q.insert({0, src});
    d[src] = 0;
    while(!q.empty())
    {
        // extract-min(q) - this edge goes into the MST
        tot += q.begin()->first;
        int u = q.begin()->second;
        q.erase(q.begin());
        vis[u] = true;
        for(pair<int, int> e : adj[u]) // e={(u, v), w}
        {
            int v = e.first, w = e.second;
            if(!vis[v] && w < d[v])
            {
                q.erase({d[v], v});
                d[v] = w; // e is in the cutset: u is already selected; v isn't
                q.insert({d[v], v});
                p[v] = u;
            }
        }
    }
    cout << "Total cost = " << tot << endl;
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    prim(1);

    // print edges of MST
    for(int i = 1; i <= n; i++)
    {
        if(p[i] != -1)
        {
            cout << p[i] << " " << i << endl;
        }
    }
    return 0;
}
/*
6 8
1 2 3
1 5 5
2 3 5
2 5 6
5 6 2
3 6 3
6 4 7
3 4 9
*/

