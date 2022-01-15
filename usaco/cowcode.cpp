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

//https://stackoverflow.com/questions/26860574/pow-implementation-in-cmath-and-efficient-replacement
unsigned long long p2 (ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;

    temp = p2 (x, y / 2);
    if ((y % 2) == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main()
{
	ifstream cin("cowcode.in");
	ofstream cout("cowcode.out");
	string s;
	ll q;
	cin >> s >> q;
	unsigned long long n = s.size();
	
	// Find the rotation that position q is located in
//	int lo = 0;
//	int hi = 63;
//	int its = -1;
//	while(lo <= hi)
//	{
//		unsigned long long mid = lo + (hi - lo) / 2;
//		if(p2(2, mid) * n >= q)
//		{
//			hi = mid - 1;
//			its = mid;
//		}
//		else
//			lo = mid + 1;
//	}
	if(q <= n)
	{
		cout << s[q - 1] << endl;
		return 0;
	}
	int i = 1;
	string r = s.substr(s.size() - 1) + s.substr(0, s.size() - 1);
	string l = s;
	while(true)
	{
		unsigned long long lensf = p2(2, i) * n;
		if(q <= lensf)
		{
			cout << r[q - lensf / 2 - 1] << endl;
			return 0;
		}
		l = l + r;
		r = l.substr(l.size() - 1) + l.substr(0, l.size() - 1);
		i++;
	}
//	return 0;
}

