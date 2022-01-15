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
    vector<int> size, parent;
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
        if(b != a)
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

int main()
{
    int n;
    cin >> n;
    dsu my_dsu(n + 1);
    return 0;
}

