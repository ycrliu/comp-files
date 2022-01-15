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

class BIT
{
    public:
        vector<long long> tree;

        BIT(int N) : tree(N)
        {}

        long long query(int k)
        {
            long long s = 0ll;

            while(k > 0)
            {
                s += tree[k];

                k -= (k & (-k));
            }

            return s;
        }

        void update(int k, long long val)
        {
            while(k < tree.size())
            {
                tree[k] += val;

                k += (k & (-k));
            }
        }
};

long long x[200005];

int main()
{
    if(fopen("test.in", "r"))
    {
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    int n, q;
    cin >> n >> q;

    BIT tr(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        
        tr.tree[i] += x[i];

        if(i + (i & (-i)) <= n)
        {
            tr.tree[i + (i & (-i))] += tr.tree[i];
        }
    }

    while(q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int k;
            long long u;
            cin >> k >> u;

            tr.update(k, -x[k]);
            x[k] = u; // update this in case we need to remove it from the tree in the future
            tr.update(k, x[k]);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            cout << tr.query(b) - tr.query(a - 1) << endl;
        }
    }
    return 0;
}

