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
 
int n, m;
int x[100005];
int mem[100005];
 
int recur(int i)
{
    if(i < 0)
    {
        return 0;
    }
    if(mem[i])
    {
        return mem[i];
    }
    int res = -1;
    if(!x[i])
    {
        int rLimit = i == n - 1 ? -1 : x[i + 1];
        int lLimit = i == 0 ? -1 : x[i - 1];
        if(lLimit == -1 && rLimit == -1)
        {
            res = m + recur(i - 1);
        }
        else if(lLimit == -1)
        {
            res = ((rLimit == 1 || rLimit == m) ? 2 : 3) + recur(i - 1);
        }
        else if(rLimit == -1)
        {
            res = ((lLimit == 1 || lLimit == m) ? 2 : 3) + recur(i - 1);
        }
        else
        {
            if(abs(rLimit - lLimit) > 2)
            {
                res = recur(i - 1);
            }
            else
            {
                res = (3 - abs(rLimit - lLimit)) + recur(i - 1);
            }
        }
    }
    else
    {
        bool l = i - 1 < 0 || abs(x[i - 1] - x[i]) <= 1;
        bool r = i + 1 >= n || abs(x[i + 1] - x[i]) <= 1;
        if(l && r)
        {
            res = 1 + recur(i - 1);
        }
        else
        {
            res = recur(i - 1);
        }
    }
    mem[i] = res;
    return res;
}
 
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << recur(n - 1) << endl;
    return 0;
}
