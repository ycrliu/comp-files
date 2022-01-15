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
using ll = long long;

array<ll, 2> a[100005];

int main()
{
	ifstream cin("pairup.in");
	ofstream cout("pairup.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i][1] >> a[i][0];
	sort(a, a + n);
	ll maxt = -1;
	int left = 0, right = n - 1;
	while(left < right)
	{
		ll pairs = min(a[left][1], a[right][1]);
//		cout << left << " " << right << " " << pairs << endl;
		a[left][1] -= pairs;
		a[right][1] -= pairs;
		maxt = max(a[left][0] + a[right][0], maxt);
		if(!a[left][1])
			left++;
		if(!a[right][1])
			right--;
	}
	// when left == right
	if(a[left][1] != 0)
		maxt = max(a[left][0] * 2ll, maxt);
	cout << maxt << endl;
	return 0;
}

