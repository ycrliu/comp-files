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
    int y, b, r;
    cin >> y >> b >> r;
    cout << min({y + y + 1 + y + 2,
                 b - 1 + b + b + 1,
                 r - 2 + r - 1 + r}) << endl;
    return 0;
}

