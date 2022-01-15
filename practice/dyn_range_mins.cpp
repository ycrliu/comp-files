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
#define MAXN 200005

using namespace std;

int n;
int x[MAXN];

class SegTree
{
    private:
        int st[4 * MAXN];

    public:
        SegTree(int N)
        {
            memset(st, INF, sizeof(st));
        }

        void build(int v, int tl, int tr)
        {
            if(tl == tr)
            {
                st[v] = x[tl];
            }
            else
            {
                int tm = (tl + tr) / 2;
                
                build(2 * v, tl, tm);
                build(2 * v + 1, tm + 1, tr);

                st[v] = min(st[2 * v], st[2 * v + 1]);
            }
        }

        int query(int v, int tl, int tr, int l, int r)
        {
            if(l > r)
            {
                return INF;
            }
            if(l == tl && r == tr)
            {
                return st[v];
            }

            int tm = (tl + tr) / 2;

            int lMin = query(2 * v, tl, tm, l, min(tm, r));
            int rMin = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
            
            return min(lMin, rMin);
        }

        void update(int v, int tl, int tr, int pos, int newVal)
        {
            if(tl == tr)
            {
                st[v] = newVal;
            }
            else
            {
                int tm = (tl + tr) / 2;
                if(pos <= tm)
                {
                    update(2 * v, tl, tm, pos, newVal);
                }
                else
                {
                    update(2 * v + 1, tm + 1, tr, pos, newVal);
                }
                st[v] = min(st[2 * v], st[2 * v + 1]);
            }
        }
};

int main()
{
    int q;
    cin >> n >> q;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }


    SegTree ans(n + 1);
    ans.build(1, 0, n - 1);

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int k, u;
            cin >> k >> u;

            ans.update(1, 0, n - 1, k - 1, u);

        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            cout << ans.query(1, 0, n - 1, a, b) << endl;
        }
    }

    return 0;
}

