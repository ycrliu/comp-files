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
    long long curS = 0;
    long long maxS = -INFLL;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        curS = max(x, curS + x);
        maxS = max(curS, maxS);
    }
    cout << maxS << endl;
    return 0;
}

