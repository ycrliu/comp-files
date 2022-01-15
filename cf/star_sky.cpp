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

long long numStars[15][105][105];

int main()
{
    int n, q, c;
    cin >> n >> q >> c;

    for(int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        numStars[s][x][y]++;
    }

    for(int s = 0; s <= c; s++)
    {
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                numStars[s][i][j] += numStars[s][i - 1][j];
                numStars[s][i][j] += numStars[s][i][j - 1];
                numStars[s][i][j] -= numStars[s][i - 1][j - 1];
            }
        }
    }

    while(q--)
    {
        long long t;
        int x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;


        long long tot = 0;
        for(int s = 0; s <= c; s++)
        {
            long long sCnt = numStars[s][x2][y2] - numStars[s][x2][y1 - 1]
                - numStars[s][x1 - 1][y2] + numStars[s][x1 - 1][y1 - 1];
            int brightness = (s + t) % (c + 1);
            
            tot += sCnt * brightness;
        }

        cout << tot << endl;
    }

    return 0;
}

