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

int n;
int x[200005];

int dp[200005];
void solve1()
{
    // o(n^2)


    int lenLIS = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(x[j] < x[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        dp[i] = max(1, dp[i]);

        lenLIS = max(dp[i], lenLIS);
    }
    
    cout << lenLIS << endl;
}

void solve2()
{
    // o(nlogn)

    vector<int> lis;

    for(int i = 0; i < n; i++)
    {
        int lo = 0;
        int hi = lis.size() - 1;
        int p = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if(x[i] <= lis[mid])
            {
                p = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        if(p != -1)
        {
            // replacing an existing number in our IS with a smaller number
            // will necessarily produce an equal or better LIS because all
            // the numbers that would have worked with lis[p] at i=p will definitely
            // work for an x[i] that is less than lis[p]
            assert(x[i] <= lis[p]);

            lis[p] = x[i];
        }
        else
        {
            // x[i] is larger than all numbers in our lis
            lis.push_back(x[i]);
        }
    }

    cout << lis.size() << endl;
}


void solve3()
{
    // o(nlogn)
    
    multiset<int> lis;

    for(int i = 0; i < n; i++)
    {
        auto it = lis.lower_bound(x[i]);
        if(it != lis.end())
        {
            lis.erase(it);
        }

        // insert into sorted position
        lis.insert(x[i]);
    }

    cout << lis.size() << endl;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    solve3();
    return 0;
}

