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

vector<pair<int, long long>> adj[100005];
long long d[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    fill(begin(d), end(d), INFLL);
    d[1] = 0ll;
    set<pair<long long, int>> q;
    q.insert({0ll, 1});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge : adj[v])
        {
            int to = edge.first;
            long long len = edge.second;
            if(d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}

