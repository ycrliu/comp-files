#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int max_n = 100005;
int height1[max_n];
int height2[max_n];
ll dp[max_n][3];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> height1[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> height2[i];
	}

	dp[0][0] = height1[0]; // Pick the i-th player from the first row
	dp[0][1] = height2[0]; // Pick the i-th player from the second row
	dp[0][2] = 0; // Skip the i-th pick -- comes in handy if a taller student in one particular line doesn't align with the alternating pattern of the greater sum path
	for(int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + height1[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + height2[i];
		dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
	return 0;
}

