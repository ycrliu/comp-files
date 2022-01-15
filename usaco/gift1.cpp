/*
ID: robertl8
LANG: C++11
PROB: gift1
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

map<string, int> money_of;
string names[11];

int main()
{
    ifstream cin("gift1.in");
    ofstream cout("gift1.out");
    int n;
    cin >> n;
    string name;
    for(int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    for(int i = 0; i < n; i++)
    {
        string giver;
        cin >> giver;
        int withdrawn, ng;
        cin >> withdrawn >> ng;
        if(ng > 0)
        {
            int amt = withdrawn / ng;
            money_of[giver] += withdrawn % ng - withdrawn;
            for(int j = 0; j < ng; j++)
            {
                string recip;
                cin >> recip;
                money_of[recip] += amt;
            }
        }
        else
        {
            money_of[giver] += withdrawn;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << names[i] << " " << money_of[names[i]] << endl;
    }
    return 0;
}

