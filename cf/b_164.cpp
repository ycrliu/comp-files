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

int main()
{
	ll n;
	cin >> n;
	ll tot = n;
	for(int i = 1; i <= n && n - i - 1 >= 0; i++)
	{
		tot += (n - i) + i * (n - i - 1);
		// (n - i - 1) -> number of buttons that causes restarts
		// i -> number of buttons already pressed
		// (n - i - 1) * i -> number of total buttons pressed to restart
	}
	cout << tot << endl;
	return 0;
}

