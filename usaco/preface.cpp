/*
ID: robertl8
LANG: C++11
TASK: preface
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
#include <cassert>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

char let[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
set<int> num;
map<int, int> letInd;
int ans[7];

void info();

int main()
{
    if(fopen("preface.in", "r"))
    {
        freopen("preface.in", "r", stdin);
        freopen("preface.out", "w", stdout);
    }

    int n;
    cin >> n;

    info();

    for(int i = 1; i <= n; i++)
    {
        int curNum = i;
        while(curNum != 0)
        {
            auto curMag = num.lower_bound(curNum);

            if((*curMag) == curNum)
            {
                ans[letInd[(*curMag)]]++;
                break;
            }

            if(curMag != num.begin())
            {
                curMag--;
                int firstDig = curNum / ((int)pow(10, (int)log10(curNum)));

                if(firstDig > 3 * (*curMag))
                {
                    ans[letInd[(*curMag)]]++;
                    curNum -= firstDig * (*curMag);

                    ans[letInd[(*(++curMag))]]++;
                }
                else
                {
                    int numMarks = curNum / (*curMag);
                    ans[letInd[(*curMag)]] += numMarks;

                    curNum -= numMarks * (*curMag);
                }
            }
            else
            {
                if(curNum == 4)
                {
                    ans[0]++;
                    ans[1]++;
                }
                else
                {
                    ans[letInd[(*curMag)]] += curNum / (*curMag);
                }
                break;
            }
        }
    }

    for(int i = 0; i < 7; i++)
    {
        if(ans[i] > 0)
        {
            cout << let[i] << " " << ans[i] << endl;
        }
    }
    return 0;
}

void info()
{
    num.insert(1);
    num.insert(5);
    num.insert(10);
    num.insert(50);
    num.insert(100);
    num.insert(500);
    num.insert(1000);
    letInd[1] = 0;
    letInd[5] = 1;
    letInd[10] = 2;
    letInd[50] = 3;
    letInd[100] = 4;
    letInd[500] = 5;
    letInd[1000] = 6;
}
