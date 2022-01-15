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

int x[200005];

int main()
{
    int n, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int ans = 0;

    int j = 0;
    int curSum = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < n && curSum + x[j] <= target)
        {
            curSum += x[j];
            j++;
        }

        if(curSum == target)
        {
            ans++;
        }

        curSum -= x[i];
    }


    cout << ans << endl;

    return 0;
}

