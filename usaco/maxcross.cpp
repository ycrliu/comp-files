#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;
using ll = long long;

int bad_ps[100005];

int main()
{
	ifstream cin("maxcross.in");
	ofstream cout("maxcross.out");
	int n, k, b;
	cin >> n >> k >> b;
	for(int i = 0; i < b; i++)
	{
		int a;
		cin >> a;
		bad_ps[a]++;
	}
	for(int i = 1; i <= n; i++)
		bad_ps[i] += bad_ps[i - 1];
	int ans = n * 5;
	for(int i = 1; i <= n - k + 1; i++)
	{
		int fix = bad_ps[i + k - 1] - bad_ps[i - 1];
//		cout << fix << endl;
		ans = min(fix, ans);
	}
	cout << ans << endl;
	return 0;
}

