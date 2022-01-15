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
        vector<int> tree;

        BIT(int N) : tree(N)
        {}

        int query(int k)
        {
            int res = 0;

            k++;

            while(k > 0)
            {
                res += tree[k];
                k -= (k & (-k));
            }
            
            return res;
        }

        void update(int k, int val)
        {
            k++;

            while(k < tree.size())
            {
                tree[k] += val;

                k += (k & (-k));
            }
        }
};


int a[MAXN];
int ps[MAXN];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ps[i] += a[i];
        if(i)
        {
            ps[i] += ps[i - 1];
        }
    }

    BIT tr(n + 1);
    
    // // o(nlogn) preprocessing
    // for(int i = 0; i < n; i++)
    // {
    //     tr.update(i, a[i]);
    // }

    // o(n) preprocessing
    for(int i = 1; i <= n; i++)
    {
        // update current node
        tr.tree[i] += a[i - 1];

        // update child
        if(i + (i & (-i)) <= n)
        {
            tr.tree[i + (i & (-i))] += tr.tree[i];
        }
    }



    for(int i = 0; i < n; i++)
    {
        cout << tr.query(i) << " " << ps[i] << endl;
    }
    return 0;
}

