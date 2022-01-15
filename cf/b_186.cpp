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

int psum[MAXN + 1];

int main()
{
	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++)
	{
		if(i + 1 < s.size())
		{
			psum[i] = s[i] == s[i + 1];
		}
		if(i > 0)
		{
			psum[i] += psum[i - 1];
		}
	}

	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int rsum = r - 1 >= 0 ? psum[r - 1] : 0;
		int lsum = l - 1 >= 0 ? psum[l - 1] : 0;
		cout << rsum - lsum << endl;
	}
	return 0;
}

