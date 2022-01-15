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
int obelisk[1005][2];
int clue[1005][2];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> obelisk[i][0] >> obelisk[i][1];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> clue[i][0] >> clue[i][1];
    }
    map<pair<int, int>, int> cnt;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x = obelisk[i][0] + clue[j][0];
            int y = obelisk[i][1] + clue[j][1];
            cnt[{x, y}]++;
        }
    }
    for(auto p : cnt)
    {
        if(p.second == n)
        {
            cout << p.first.first << " " << p.first.second << endl;
        }
    }
    return 0;
}

