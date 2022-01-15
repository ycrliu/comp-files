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

constexpr int sz = 200005;
ll b[sz];

int main()
{
	int n;
	cin >> n;
	ll maxb = -INFLL;
	ll minb = INFLL;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		maxb = max(b[i], maxb);
		minb = min(b[i], minb);
	}
	ll nmin = 0;
	ll nmax = 0;
	for(int i = 0; i < n; i++)
	{
		nmax += (b[i] == maxb);
		nmin += (b[i] == minb);
	}
	cout << maxb - minb << " " << nmax * nmin << endl;
	return 0;
}

