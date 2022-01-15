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
    
    // min number of moves to make array non-decreasing
    // = length of array - length of longest non-decreasing subsequence

    vector<int> lnds;
    for(int i = 0; i < n; i++)
    {
        int spec;
        cin >> spec >> trash;

        int lo = 0;
        int hi = lnds.size() - 1;
        int p = -1;

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(spec < lnds[mid])
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
            lnds[p] = spec;
        }
        else
        {
            lnds.push_back(spec);
        }
    }

    cout << n - (int)(lnds.size()) << endl;

    return 0;
}

