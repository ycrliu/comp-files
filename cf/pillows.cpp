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

//long long getTot(int cur, int start, int end, int dir)
//{
//    long long tot = 0;
//    int i = start;
//    for(int i = start;; i += dir)
//    {
//        tot += cur;
//        if(cur - 1 == 0)
//        {
//            return tot + abs(end - i);
//        }
//        cur--;
//
//        if(i == end)
//        {
//            return tot;
//        }
//    }
//}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    int lo = 0;
    int hi = m;
    int ans = -1;
    while(lo <= hi)
    {
        long long mid = (lo + hi + 1) / 2ll;
//        long long rTot = k + 1 <= n ? getTot(mid - 1, k + 1, n, 1) : 0;
//        long long lTot = k - 1 >= 1 ? getTot(mid - 1, k - 1, 1, -1) : 0;

        long long rTot = 0ll;
        long long lTot = 0ll;

        if(n - k > 0)
        {
            if(mid - 1 > n - k)
            {
                rTot = ((n - k) * (mid - 1 + (mid - 1 - (n - k - 1)))) / 2;
            }
            else if(mid - 1 == n - k)
            {
                rTot = ((mid - 1) * (mid - 1 + 1)) / 2;
            }
            else
            {
                rTot = ((mid - 1) * (mid - 1 + 1)) / 2 + 1 * (n - (k + mid - 1));
            }
        }

        if(k - 1 > 0)
        {
            if(mid - 1 > k - 1)
            {
                lTot = ((k - 1) * (mid - 1 + (mid - 1 - (k - 1 - 1)))) / 2;
            }
            else if(mid - 1 == k - 1)
            {
                lTot = ((k - 1) * (mid - 1 + 1)) / 2;
            }
            else
            {
                lTot += ((mid - 1) * (mid - 1 + 1)) / 2 + 1 * ((k - (mid - 1) - 1));
            }
        }

//        cout << mid << " " << lTot << " " << rTot << endl;
        if(mid + rTot + lTot <= m)
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

