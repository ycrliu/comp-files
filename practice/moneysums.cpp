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

int x[105];
bool possible[100005][105];
// possible[i][j] = can we construct i using the first j items

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++)
    {
        possible[0][i] = true;
        possible[x[i]][i] = true;
    }
    set<int> is;
    for(int i = 1; i <= 1000 * n; i++)
    {
        bool yes = false;
        for(int j = 1; j <= n; j++)
        {
            if(j - 1 > 0)
            {
                possible[i][j] |= possible[i][j - 1];
            }
            if(i - x[j] >= 0)
            {
                possible[i][j] |= possible[i - x[j]][j - 1];
            }
            yes |= possible[i][j];
        }
        if(yes)
        {
            is.insert(i);
        }
    }
    cout << is.size() << endl;
    for(int i : is)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

