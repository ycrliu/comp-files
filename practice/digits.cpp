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

//int mem[1000005];
//int recur(int n)
//{
//    if(n == 0)
//    {
//        return 0;
//    }
//    if(mem[n])
//    {
//        return mem[n];
//    }
//    int nC = n;
//    int res = INF;
//    while(nC != 0)
//    {
//        int d = nC % 10;
//        // if d is 0, this fcn recurses infinitely
//        if(d != 0 && n - d >= 0)
//        {
//            res = min(1 + recur(n - d), res);
//        }
//        nC /= 10;
//    }
//    mem[n] = res;
//    return res;
//}

int dp[1000005];

int main()
{
    int n;
    cin >> n;
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i <= n; i++)
    {
        int iC = i;
        while(iC != 0)
        {
            int d = iC % 10;
            if(d != 0 && i - d >= 0)
            {
                dp[i] = min(1 + dp[i - d], dp[i]);
            }
            iC /= 10;
        }
    }
    cout << dp[n] << endl;
//    cout << recur(n) << endl;
    return 0;
}

