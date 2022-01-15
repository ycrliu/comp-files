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

int dp[1000005];

int main()
{
    string s;
    cin >> s;

    int len = s.size();
    int lC = 0;
    int rC = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            lC++; // new '('
        }
        else
        {
            if(lC == 0)
            {
                len--; // no '(' to match current ')' with so remove the current ')'
            }
            else
            {
                rC++; // add the current ')' because we can match it
                lC--;
            }
        }
    }

    // count all '(' because we don't know if we can match them yet.
    // however, count only the ')'s we can match because we already know, when we
    // reach that ')', whether it can be matched to an existing '('

    cout << len - lC << endl; // get rid of excess '('
    return 0;
}

