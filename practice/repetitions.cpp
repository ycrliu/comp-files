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
    string s;
    cin >> s;
    int maxL = 0;
    int curL = 0;
    char last = '\0';
    for(char c : s)
    {
        if(c == last)
        {
            curL++;
        }
        else
        {
            curL = 1;
            last = c;
        }
        maxL = max(curL, maxL);
    }
    cout << maxL << endl;
    return 0;
}

