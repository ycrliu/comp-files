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

pair<int, int> a[100005];

int main()
{
    int n;
    cin >> n;

    int zeroes = 0;
    int negs = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        a[i].first = i;
        negs += (a[i].second < 0);
        zeroes += (a[i].second == 0);
    }
    sort(a, a + n, [](const pair<int, int>& p1, const pair<int, int>& p2)
            {
                return p1.second < p2.second;
            });

    if(n % 2 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            a[i].second = a[i].second >= 0 ? -a[i].second - 1 : a[i].second;
        }
    }
    else
    {
        if((negs + zeroes) % 2 == 0)
        {
            if(n - negs - zeroes > 2)
            {
                for(int i = n - 1; i > negs + zeroes; i--)
                {
                    a[i].second = -a[i].second - 1;
                }
                for(int i = negs + zeroes; i >= 0; i--)
                {
                    a[i].second = !a[i].second ? -1 : a[i].second;
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    a[i].second = !a[i].second ? -1 : a[i].second;
                }
            }
        }
        else
        {
            if(n - negs - zeroes == 0)
            {
                if(n > 1)
                {
                    bool hasZero = false;
                    int i = n - 1;
                    for(; i >= 0; i--)
                    {
                        if(a[i].second == 0)
                        {
                            a[i].second = -1;
                            hasZero = true;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(hasZero)
                    {
                        a[0].second = -a[0].second - 1;
                    }
                }
                else
                {
                    if(a[0].second != 0)
                    {
                        a[0].second = -a[0].second - 1;
                    }
                }
            }
            else
            {
                for(int i = n - 1; i > negs + zeroes; i--)
                {
                    a[i].second = -a[i].second - 1;
                }
                for(int i = negs + zeroes; i >= 0; i--)
                {
                    a[i].second = !a[i].second ? -1 : a[i].second;
                }
            }
        }
    }
    sort(a, a + n, [](const pair<int, int>& p1, const pair<int, int>& p2)
            {
                return p1.first < p2.first;
            });
    for(int i = 0; i < n; i++)
    {
        cout << a[i].second << " ";
    }
    cout << endl;
    return 0;
}

