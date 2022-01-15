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

int a[200005];

int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> ind_of;
    for(int i = 1; i <= n; i++)
    {
        if(ind_of[x - a[i]])
        {
            cout << i << " " << ind_of[x - a[i]] << endl;
            return 0;
        }
        ind_of[a[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

