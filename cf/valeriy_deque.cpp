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

int main()
{
    int n, q;
    cin >> n >> q;
    
    deque<long long> d(n);
    long long maxA = LLONG_MIN;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
        maxA = max(d[i], maxA);
    }

    vector<pair<int, int>> ans;
    int i = 0;
    for(; i < n; i++)
    {
        int a = d.front();
        if(a == maxA)
        {
            break;
        }
        d.pop_front();
        int b = d.front();
        d.pop_front();

        ans.push_back({a, b});

        if(a > b)
        {
            d.push_front(a);
            d.push_back(b);
        }
        else
        {
            d.push_front(b);
            d.push_back(a);
        }
    }

    while(q--)
    {
        long long m;
        cin >> m;
        m--;
        
        if(m < i)
        {
            cout << ans[m].first << " " << ans[m].second << endl;
        }
        else
        {
            m -= i;
            m %= (n - 1);
            m++;

            cout << maxA << " " << d[m] << endl;
        }
    }
    return 0;
}

