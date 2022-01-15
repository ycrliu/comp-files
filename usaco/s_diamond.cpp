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

int sizes[50005];

int main()
{
	ifstream cin("diamond.in");
	ofstream cout("diamond.out");
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> sizes[i];
	sort(sizes, sizes + n);
	int li = 0, lj = 0, ans = -1;
	while(li < n)
	{
		while(lj + 1 < n && sizes[lj + 1] - sizes[li] <= k)
			lj++;
		for(int ri = lj; ri < n; ri++)
		{
			int rj = ri;
			while(rj + 1 < n && sizes[rj + 1] - sizes[ri] <= k)
				rj++;
			int ca = rj - ri + lj - li + 2;
//			cout << ca << " " << li << " " << lj << " " << ri << " " << rj << endl;
			ans = max(ca, ans);
		}
		li++;
	}
	cout << ans << endl;
	return 0;
}

