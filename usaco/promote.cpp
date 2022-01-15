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

int a[4][2];

int main()
{
    ifstream cin("promote.in");
    ofstream cout("promote.out");
    for(int i = 0; i < 4; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for(int curD = 1; curD < 4; curD++)
    {
        int tot = 0;
        for(int d = curD; d < 4; d++)
        {
            tot += a[d][1] - a[d][0];
        }
        cout << tot << endl;
    }
    return 0;
}

