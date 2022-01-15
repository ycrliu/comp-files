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
#define MAXN 100000

using namespace std;

struct dsu
{
    int n;
    vector<int> size;
    vector<int> parent;
    dsu(int N) : n(N), size(N), parent(N)
    {
    }
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
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(b != a)
        {
            if(size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    dsu net(n + 1);
    for(int i = 1; i <= n; i++)
    {
        net.make_set(i);
    }
    for(int i = 0, k; i < m; i++)
    {
        cin >> k;
        if(k > 0)
        {
            vector<int> group(k);
            for(int j = 0; j < k; j++)
            {
                cin >> group[j];
            }
            for(int j = 0; j < k; j++)
            {
                net.union_set(group[0], group[j]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << net.size[net.find_set(i)] << (i == n ? "\n" : " ");
    }
    return 0;
}

