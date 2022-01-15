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

const int MAXC = 1e6 + 5;
string ramp[105];
int lo[105];
int hi[105];

int main()
{
	ifstream cin("traffic.in");
	ofstream cout("traffic.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> ramp[i] >> lo[i] >> hi[i];
	}
	int smin = -MAXC, smax = MAXC;
	for(int i = n - 1; i >= 0; i--)
	{
		if(ramp[i] == "on")
		{
			smin = max(0, smin - hi[i]);
			smax = max(0, smax - lo[i]);
		}
		else if(ramp[i] == "off")
		{
			smin += lo[i];
			smax += hi[i];
		}
		else
		{
			smin = max(lo[i], smin);
			smax = min(hi[i], smax);
		}
	}
	int emin = -MAXC, emax = MAXC;
	for(int i = 0; i < n; i++)
	{
		if(ramp[i] == "on")
		{
			emin += lo[i];
			emax += hi[i];
		}
		else if(ramp[i] == "off")
		{
			emin = max(0, emin - hi[i]);
			emax = max(0, emax - lo[i]);
		}
		else
		{
			emin = max(lo[i], emin);
			emax = min(hi[i], emax);
		}
	}
	assert(smin <= smax && emin <= emax);
	cout << smin << " " << smax << endl;
	cout << emin << " " << emax << endl;
	return 0;
}

