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
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;
const int INF = 1000000000;


int n;
vector<pair<int, int>> adj[MAXN];

void prim1(int src) {
    int total_weight = 0;
    vector<pair<int, int>> min_e(n + 1);
    for(int i = 1; i <= n; i++)
    {
        min_e[i] = {-1, INF};
    }
    min_e[src].second = 0;
    set<pair<int, int>> q;
    q.insert({0, src});
    vector<bool> selected(n + 1, false);
    while(!q.empty())
    {
        int v = q.begin()->second;
        selected[v] = true;
        total_weight += q.begin()->first;
        q.erase(q.begin());

        if (min_e[v].first != -1)
            cout << v << " " << min_e[v].first << endl;

        for (pair<int, int> e : adj[v]) {
            if (!selected[e.first] && e.second < min_e[e.first].second) {
                q.erase({min_e[e.first].second, e.first});
                min_e[e.first] = {v, e.second};
                q.insert({e.second, e.first});
            }
        }
    }

    cout << "Total cost = " << total_weight << endl;
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

    return 0;
}

