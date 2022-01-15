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
#define MAXN 10000

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int given = 0;
	int res = 0;
	bool done = false;
	for(int i = 0, a; i < n; i++)
	{
		cin >> a;
		res += a;

		int max_possible = min(8, res);
		given += max_possible;
		res -= max_possible;

		if(given >= k)
		{
			cout << i + 1 << endl;
			done = true;
			break;
		}
		if(res < 0)
		{
			break;
		}
	}
	if(!done)
	{
		cout << -1 << endl;
	}
	return 0;
}

