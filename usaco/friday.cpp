/*
ID: robertl8
LANG: C++11
PROB: friday
*/
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

int ans[7]; // sat, sun, ..., friday

bool is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year)
{
    if(month == 9 || month == 4 || month == 6 || month == 11)
    {
        return 30;
    }
    else if(month == 2)
    {
        return is_leap(year) ? 29 : 28;
    }
    else
    {
        return 31;
    }
}

int main()
{
    ifstream cin("friday.in");
    ofstream cout("friday.out");
    int n;
    cin >> n;
    int day = 0;
    for(int year = 1900; year <= 1900 + n - 1; year++)
    {
        for(int month = 1; month <= 12; month++)
        {
            int days = days_in_month(month, year);
            for(int it = 1; it <= days; it++)
            {
                if(it == 13)
                {
                    ans[(day + 2) % 7]++;
                }
                day = (day + 1) % 7;
            }
        }
    }
    for(int i = 0; i < 7; i++)
    {
        cout << ans[i] << (i == 6 ? "\n" : " ");
    }
    return 0;
}

