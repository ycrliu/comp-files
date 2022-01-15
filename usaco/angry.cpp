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
#include <cassert>

using namespace std;

int n;
int bale[105];

int explode(int i, int di)
{
	int radius = 1;
	int tot = 1; // Include the current haybale

	while(i < n && i >= 0)
	{
		int j = i;
		while(j + di < n && j + di >= 0 && abs(bale[j + di] - bale[i]) <= radius)
		{
			j += di;
		}
		if(i == j)
		{
			break;
		}
		tot += abs(j - i);
		i = j;
		radius++;
	}
	return tot;
}

int main()
{
	ifstream cin("angry.in");
	ofstream cout("angry.out");

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> bale[i];
	}
	sort(bale, bale + n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(explode(i, 1) + explode(i, -1) - 1, ans);
	}
	cout << ans << endl;
	return 0;
}

