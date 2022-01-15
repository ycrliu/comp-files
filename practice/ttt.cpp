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

string bitForm(int n)
{
    string res;
    
    for(int i = 31; i >= 0; i--)
    {
        if((n & (1 << i)) > 0)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << bitForm(n) << endl;
    cout << bitForm(-n) << endl;
    cout << bitForm(n & (-n)) << endl;
    return 0;
}

