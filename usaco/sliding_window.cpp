// "sliding window"
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

bool bad[100005];

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
		bad[a] = true;
	}
	int cur_bad = 0;
	for(int i = 1; i <= k; i++)
		if(bad[i])
			cur_bad++;
	int ans = n * 5;
	ans = min(cur_bad, ans);
	int left = 1;
	int right = k;
	while(right <= n)
	{
		right++;
		if(bad[left])
			cur_bad--;
		if(bad[right])
			cur_bad++;
		ans = min(cur_bad, ans);
		left++;
	}
	cout << ans << endl;
	return 0;
}

