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

string bgs[105];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        for(int i = 0; i < n - 2; i++)
        {
            cin >> bgs[i];
            s.push_back(bgs[i][0]);
        }
        s.push_back(bgs[n - 2][1]);
        cout << s + "a" << endl;
    }
    return 0;
}

