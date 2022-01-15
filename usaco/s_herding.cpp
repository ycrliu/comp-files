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

int a[100005];

int main()
{
	ifstream cin("herding.in");
	ofstream cout("herding.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	
	// max ans: Number of empty spaces, with the smaller of the first/last gap sacrificed
	int max_ans = a[n - 1] - a[0] - (n - 2) - min(a[n - 1] - a[n - 2], a[1] - a[0]);

	// min ans: window of length n with highest number of already occupied squares
	int most_occ = 0;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		for(; j + 1 < n && a[j + 1] - a[i] + 1 <= n; j++);
		most_occ = max(most_occ, j - i + 1);
	}
	int min_ans = 0;
	// if there are n-1 consecutive cows and an additional cow more than 1 space away, only 2 moves are required (no matter the distance of the last cow)
	if((a[n - 2] - a[0] + 1 == n - 1 && a[n - 1] - a[n - 2] > 2) || (a[n - 1] - a[1] + 1 == n - 1 && a[1] - a[0] > 2))
		min_ans = 2;
	else
		min_ans = n - most_occ;

	cout << min_ans << endl << max_ans << endl;
	return 0;
}

