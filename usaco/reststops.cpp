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

array<int, 2> stops[100005];
bool is_max_so_far[100005];

int main()
{
	ifstream cin("reststops.in");
	ofstream cout("reststops.out");

	int L, n, rF, rB;
	cin >> L >> n >> rF >> rB;
	for (int i = 0; i < n; i++)
	{
		cin >> stops[i][0] >> stops[i][1];
	}
	sort(stops, stops + n);

	int max_so_far = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (stops[i][1] > max_so_far)
		{
			is_max_so_far[i] = true;
			max_so_far = stops[i][1];
		}
	}

	// Only pick rest stops that have no subsequent stops of greater or equal tastiness
	ll total_tast = 0;
	int last_stop = 0;
	for (int i = 0; i < n; i++)
	{
		if (is_max_so_far[i])
		{
			ll ttr_bessie = (stops[i][0] - last_stop) * ((ll)rB); 
			ll ttr_farmer = (stops[i][0] - last_stop) * ((ll)rF);
			total_tast += (ttr_farmer - ttr_bessie) * stops[i][1];
			last_stop = stops[i][0];
		}
	}

	cout << total_tast << endl;
	return 0;
}

