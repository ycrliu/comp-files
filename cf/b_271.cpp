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
#define MAXN 100000

using namespace std;

int nw[MAXN + 1];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> nw[i];
		if(i > 0)
		{
			nw[i] += nw[i - 1];
		}
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int q;
		cin >> q;
		
		int lo = 0;
		int hi = n;
		int ans = -1;
		while(lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if(nw[mid] >= q)
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}

