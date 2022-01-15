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

int n;
int canvas[11][11];
bool can[10];

// returns {min row, max row, min col, max col}
array<int, 4> corners(int color)
{
    array<int, 4> res = {n, -1, n, -1};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(canvas[i][j] == color)
            {
                res[0] = min(i, res[0]);
                res[1] = max(i, res[1]);
                res[2] = min(j, res[2]);
                res[3] = max(j, res[3]);
            }
        }
    }
    return res;
}

// check if c1 overlaps c2
bool overlap(int c1, int c2)
{
    array<int, 4> c2b = corners(c2);
    for(int i = c2b[0]; i <= c2b[1]; i++)
    {
        for(int j = c2b[2]; j <= c2b[3]; j++)
        {
            if(canvas[i][j] == c1)
            {
                return true;
            }
        }
    }
    for(int j = c2b[2]; j <= c2b[3]; j++)
    {
        for(int i = c2b[0]; i <= c2b[1]; i++)
        {
            if(canvas[i][j] == c1)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream cin("art.in");
    ofstream cout("art.out");
    cin >> n;
    set<int> onBoard;
    for(int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        for(int j = 0; j < n; j++)
        {
            canvas[i][j] = l[j] - '0';
            if(canvas[i][j] != 0)
            {
                onBoard.insert(canvas[i][j]);
            }
        }
    }
    fill(begin(can), end(can), true);
    for(int curC : onBoard)
    {
        for(int c : onBoard)
        {
            if(c != curC)
            {
                if(overlap(curC, c))
                {
                    can[curC] = false;
                }
            }
        }
    }
    int ans = 0;
    for(int c : onBoard)
    {
        if(can[c])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

