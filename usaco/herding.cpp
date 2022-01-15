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

int main()
{
	ifstream cin("herding.in");
	ofstream cout("herding.out");
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int lo = 0;
	int hi = 0;
	int d1 = a[1] - a[0];
	int d2 = a[2] - a[1];
	if(d1 > 1 || d2 > 1)
	{
		if(d1 == 2 || d2 == 2)
		{
			lo = 1;
			hi = max(d1, d2) - 1;
		}
		else
		{
			hi = max(d1, d2) - 1;
			lo = hi == 1 ? 1 : 2;
		}
	}
	cout << lo << endl << hi << endl;
	return 0;
}

