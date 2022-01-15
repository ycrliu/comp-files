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

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    long long prev = -1;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if(i > 0)
        {
            if(x < prev)
            {
                ans += prev - x;
            }
            else
            {
                prev = x;
            }
        }
        else
        {
            prev = x;
        }
    }
    cout << ans << endl;
    return 0;
}

