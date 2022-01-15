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
 
int dp[505][505];
//dp[h][w] = min # of moves to cut h x w rectangle into squares
 
int main()
{
	int a, b;
	cin >> a >> b;
	memset(dp, 0x3f, sizeof dp);
	for(int h = 0; h <= a; h++)
	{
		for(int w = 0; w <= b; w++)
		{
			if(h == w)
				dp[h][w] = 0;
			// try all horizontal cuts using the data we have so far
			for(int k = 1; k <= h; k++)
				dp[h][w] = min(dp[h][w], dp[k][w] + dp[h - k][w] + 1);
			// try all vertical cuts using the data we have so far
			for(int k = 1; k <= w; k++)
				dp[h][w] = min(dp[h][w], dp[h][k] + dp[h][w - k] + 1);
		}
	}
	cout << dp[a][b];
	return 0;
}
