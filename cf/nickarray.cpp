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

int a[100005];

int main()
{
    int n;
    cin >> n;

    int minN = INT_MAX, minI = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] >= 0)
        {
            a[i] = -a[i] - 1;
        }
        if(a[i] < minN)
        {
            minI = i;
            minN = a[i];
        }
    }

    if(n % 2 == 1)
    {
        a[minI] = -a[minI] - 1;
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

