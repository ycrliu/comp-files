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
#include <stack>

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

    stack<pair<int, int>> stck;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        while(!stck.empty() && stck.top().first >= x)
        {
            stck.pop();
        }
        
        if(stck.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << stck.top().second << " ";
        }
        stck.push({x, i});
    }
    cout << endl;
    return 0;
}

