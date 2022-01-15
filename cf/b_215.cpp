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

constexpr int sz = 100001;
int a[sz];
int ssum[sz];
bool seen[sz];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
//	set<int> seen; array - more efficient than set
	for(int i = n - 1; i >= 0; i--)
	{
		if(!seen[a[i]])
		{
			ssum[i]++;
		}
		if(i < n - 1)
		{
			ssum[i] += ssum[i + 1];
		}
		seen[a[i]] = 1;
	}
	for(int i = 0, l; i < m; i++)
	{
		cin >> l;
		cout << ssum[l - 1] << endl;
	}
	return 0;
}

