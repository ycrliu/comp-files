#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int max_n = 100 + 5;
int availability[max_n];
int min_rest_so_far[max_n][3];
	// 0 = did a contest on i-th day
	// 1 = did sports on i-th day
	// 2 = rested on i-th day

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> availability[i];
	}

	for(int i = 0; i < n; i++)
	{
		fill(begin(min_rest_so_far[i]), end(min_rest_so_far[i]), INT_MAX);
	}

	if(availability[0] == 1 || availability[0] == 3)
	{
		min_rest_so_far[0][0] = 0;
	}
	if(availability[0] == 2 || availability[0] == 3)
	{
		min_rest_so_far[0][1] = 0;
	}
	min_rest_so_far[0][2] = 1;
	
	for(int i = 1; i < n; i++)
	{
		min_rest_so_far[i][2] = 1 + min({min_rest_so_far[i - 1][0], min_rest_so_far[i - 1][1], min_rest_so_far[i - 1][2]});
		if(availability[i] == 1 || availability[i] == 3)
		{
			min_rest_so_far[i][0] = min(min_rest_so_far[i - 1][1], min_rest_so_far[i - 1][2]);
		}
		if(availability[i] == 2 || availability[i] == 3)
		{
			min_rest_so_far[i][1] = min(min_rest_so_far[i - 1][0], min_rest_so_far[i - 1][2]);
		}
	}
	cout << min({min_rest_so_far[n - 1][0], min_rest_so_far[n - 1][1], min_rest_so_far[n - 1][2]}) << endl;
	return 0;
}

