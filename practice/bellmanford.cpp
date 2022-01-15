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
int d[MAXN];

vector<tuple<int, int, int>> edges;
int p[MAXN];
void bellmanford(int src)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[src] = 0;
    while(true)
    {
        bool any = false;
        for(auto e : edge)
        {
            int v = get<0>(e), to = get<1>(e), w = get<2>(e);
            // prevent int overflow with negative edges + only perform a relaxation
            // from an already relaxed edge
            if(d[v] < INF)
            {
                if(d[v] + w < d[to])
                {
                    any = true;
                    d[to] = d[v] + w;
                    p[to] = v;
                }
            }
        }
        if(!any)
        {
            break;
        }
    }
}

void detect_neg_cyc(int src)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[src] = 0;
    int x;
    for(int i = 0; i < n; i++)
    {
        // if there are no negative cycles, x will remain -1 on the nth iteration
        // otherwise BF will perform relaxations infinitely
        x = -1;
        for(auto e : edges)
        {
            int v = get<0>(e), to = get<1>(e), w = get<2>(e);
            if(d[v] < INF)
            {
                if(d[v] + len < d[to])
                {
                    d[to] = d[v] + len;
                    p[to] = v;

                    x = to;
                }
            }
        }
    }
    if(x == -1)
    {
        cout << "no negative cycles\n";
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            x = p[x];
        }
        vector<int> path;
        for(int v = x;; v = p[v])
        {
            path.push_back(v);
            if(v == x && path.size() > 1)
            {
                break;
            }
        }
        reverse(path.begin(), path.end());
        cout << "negative cycle: ";
        for(int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}

vector<int> adj[MAXN];
bool inQ[MAXN];
int cnt[MAXN];
bool spfa(int src)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));

    // contains only vertices that were relaxed that could further relax their neighbors
    queue<int> q;
    d[src] = 0;
    q.push(src);
    inQ[src] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        inQ[v] = false;
        for(auto e : adj[v])
        {
            int to = e.first;
            int len = e.second;
            
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                if(!inQ[to])
                {
                    q.push(to);
                    inQ[to] = true;
                    cnt[to]++;
                    // negative cycle
                    if(cnt[to] > n)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    bellmanford();
    spfa();
    return 0;
}

