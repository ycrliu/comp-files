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

vector<pair<int, long long>> adj[100005];
long long d[100005];
int p[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    memset(p, -1, sizeof(p));
    memset(d, INFLL, sizeof(d));
    set<pair<long long, int>> q;
    d[1] = 0ll;
    q.insert({0ll, 1});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(pair<int, int> edge : adj[v])
        {
            int to = edge.first;
            long long len = edge.second;
            if(d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    if(d[n] < INFLL)
    {
        vector<int> path;
        for(int v = n; v != 1; v = p[v])
        {
            path.push_back(v);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << (i == path.size() - 1 ? "\n" : " ");
        }
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}

