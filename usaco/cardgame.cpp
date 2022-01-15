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
    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");
    int n;
    cin >> n;
    map<int, bool> isE;
    map<int, int> eGame;
    for(int i = 0; i < n; i++)
    {
        int ec;
        cin >> ec;
        isE[ec] = true;
        if(i < n / 2)
        {
            eGame[ec] = 1;
        }
        else
        {
            eGame[ec] = 2;
        }
    }
    vector<int> e1, e2, b; // all are sorted
    for(int i = 1; i <= 2 * n; i++)
    {
        if(isE[i])
        {
            if(eGame[i] == 1)
            {
                e1.push_back(i);
            }
            else
            {
                e2.push_back(i);
            }
        }
        else
        {
            b.push_back(i);
        }
    }
    int ans = 0;

    int done1 = 0;
    for(int i = n - 1; i >= n / 2; i--)
    {
        for(int j = n / 2 - 1 - done1; j >= 0; j--)
        {
            done1++;
            if(b[i] > e1[j])
            {
                ans++;
                break;
            }
        }
    }
    int done2 = 0;
    for(int i = 0; i < n / 2; i++)
    {
        for(int j = done2; j < n / 2; j++)
        {
            done2++;
            if(b[i] < e2[j])
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

