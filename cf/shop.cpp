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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        map<int, int> bound;

        int minN = INT_MAX;
        int maxN = INT_MIN;
        int maxLen = INT_MIN;
        long long minC = LLONG_MAX;
        long long maxC = LLONG_MAX;
        long long lenC = LLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            int l, r;
            long long c;
            cin >> l >> r >> c;

            if(l < minN)
            {
                minC = c;
                minN = l;
            }
            else if(l == minN && c < minC)
            {
                minC = c;
            }

            if(r > maxN)
            {
                maxC = c;
                maxN = r;
            }
            else if(r == maxN && c < maxC)
            {
                maxC = c;
            }

            if(r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                lenC = c;
            }
            else if(r - l + 1 == maxLen && c < lenC)
            {
                lenC = c;
            }

            long long ans = minC + maxC;
            if(maxN - minN + 1 == maxLen)
            {
                ans = min(lenC, ans);
            }
            cout << ans << endl;
        }
    }
    return 0;
}

