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
long long x[MAXN];

class BIT
{
    public:
        vector<long long> tr;

        BIT(int N) : tr(N)
        {}

        long long query(int k)
        {
            long long s = 0ll;

            while(k > 0)
            {
                s += tr[k];
                k -= (k & (-k));
            }

            return s;
        }

        void update(int k, long long val)
        {
            while(k < tr.size())
            {
                tr[k] += val;
                k += (k & (-k));
            }
        }
};

int main()
{
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }


    BIT ft(n + 2);

    for(int i = 1; i <= n; i++)
    {
        ft.tr[i] += x[i];

        if(i + (i & (-i)) <= n)
        {
            ft.tr[i + (i & (-i))] += ft.tr[i];
        }
    }

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int a, b;
            long long u;
            cin >> a >> b >> u;

            ft = BIT(n + 2);

            ft.tr[a] += u;
            ft.tr[b + 1] -= u;

            for(int i = 1; i <= n; i++)
            {
                ft.tr[i] += x[i];

                if(i + (i & (-i)) <= n)
                {
                    ft.tr[i + (i & (-i))] += ft.tr[i];
                }
            }
        }
        else
        {
            int k;
            cin >> k;

            cout << ft.query(k) - (k == 1 ? 0 : ft.query(k - 1)) << endl;
        }
    }
    return 0;
}

