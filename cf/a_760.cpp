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

int b[7];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 7; i++)
        {
            cin >> b[i];
        }
        int a1 = b[0];
        int a2 = b[1];
        int a3 = b[2];
        if(a1 + a2 + a3 == b[6])
        {
            cout << a1 << " " << a2 << " " << a3 << endl;
        }
        else
        {
            if(a1 + a2 + b[3] == b[6])
            {
                cout << a1 << " " << a2 << " " << b[3] << endl;
            }
            else if(a1 + b[2] + b[3] == b[6])
            {
                cout << a1 << " " << b[2] << " " << b[3] << endl;
            }
        }
    }
    return 0;
}

