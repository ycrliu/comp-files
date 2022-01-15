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

int main()
{
    double trash;
    int n;
    cin >> n >> trash;

    multiset<int> lnds;
    for(int i = 0; i < n; i++)
    {
        int spec;
        cin >> spec >> trash;
        
        auto it = lnds.upper_bound(spec);
        if(it != lnds.end())
        {
            lnds.erase(it);
        }
        
        lnds.insert(spec);
    }

    cout << n - (int)(lnds.size()) << endl;
    return 0;
}

