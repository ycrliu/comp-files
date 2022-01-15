// O(Nlogn) - sorting + o(n) loop: same as set insert but way more code
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

int x[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    int i = 0;
    int ans = 0;
    while(i < n)
    {
        int j = i + 1;
        while(j < n && x[j] == x[i])
        {
            j++;
        }
        i = j;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

