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

long long x[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    long long curSum = 0;
    // curSum[i] + 1 is the smallest subset sum from 0 to i unable to be formed
    // by coins from 0 to i
    for(int i = 0; i < n; i++)
    {
        if(x[i] > curSum + 1)
        {
            break;
        }
        curSum += x[i];
    }
    cout << curSum + 1 << endl;
    return 0;
}

