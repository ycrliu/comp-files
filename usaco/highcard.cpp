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

int main()
{
    ifstream cin("highcard.in");
    ofstream cout("highcard.out");
    int n;
    cin >> n;
    map<int, bool> isE;
    for(int i = 0, ec; i < n; i++)
    {
        cin >> ec;
        isE[ec] = true;
    }
    vector<int> e, b;
    for(int i = 1; i <= 2 * n; i++)
    {
        if(isE[i])
        {
            e.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    // e and b are sorted already
    int ans = 0;
    int rounds_done = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n - 1 - rounds_done; j >= 0; j--)
        {
            rounds_done++;
            if(b[i] > e[j])
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

