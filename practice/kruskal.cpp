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

struct dsu
{
    vector<int> size;
    vector<int> parent;
    int n;
    dsu(int N) : n(N), size(N), parent(N)
    {}
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v)
    {
        if(v == parent[v])
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a != b)
        {
            if(size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

int n;
vector<tuple<int, int, int>> edges; // {u, v, w}
vector<tuple<int, int, int>> res;

bool sort_by_w(const tuple<int, int, int>&a, const tuple<int, int, int>& b)
{
    return get<2>(a) < get<2>(b);
}

// mst contains exactly n-1 edges; we could stop the loop once we've found
// that many
void kruskal()
{
    int cost = 0;
    dsu K(n + 1);
    for(int i = 1; i <= n; i++)
    {
        K.make_set(i);
    }
    sort(edges.begin(), edges.end(), sort_by_w);
    for(auto e : edges)
    {
        int u = get<0>(e), v = get<1>(e), w = get<2>(e);
        if(K.find_set(u) != K.find_set(v))
        {
            cost += w;
            res.push_back(e);
            K.union_sets(u, v);
        }
    }
    cout << "Total cost = " << cost << endl;
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    kruskal();

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

