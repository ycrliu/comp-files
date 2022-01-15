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

set<int> nodes;
vector<pair<int, int>> adj[105];

bool hasCycle;
int vis[105];
// 0 - yet processed
// 1 - under processing
// 2 - has been processed

bool vis2[105];


void dfs(int u)
{
    vis[u] = 1;
    for(auto succ : adj[u])
    {
        if(!vis[succ.first])
        {
            dfs(succ.first);
        }
        else if(vis[succ.first] == 1)
        {
            hasCycle = true;
        }
    }
    vis[u] = 2;
}

int dfs2(int u, int totC)
{
    vis2[u] = true;
    int minC = INF;
    bool sink = true;

    for(auto succ : adj[u])
    {
        if(!vis2[succ.first])
        {
            sink = false;

            int tmp = dfs2(succ.first, totC + succ.second);
            minC = min(tmp, minC);
        }
    }
    if(sink)
    {
        vis[u] = false;
        return totC;
    }

    return minC;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        nodes.insert(a);
        nodes.insert(b);
    }
    
    for(int node : nodes)
    {
        if(!vis[node])
        {
            dfs(node);
        }
    }

    if(!hasCycle)
    {
        int minC = INF;
        for(int node : nodes)
        {
            if(!vis2[node])
            {
                minC = min(dfs2(node, 0), minC);
            }
        }
        cout << minC << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    return 0;
}

