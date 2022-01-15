#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MAXN 100000

using namespace std;

constexpr int sz = 3001;
map<string, int> lena;
map<string, int> lenb;
map<string, string> translate;

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;
		lena[a] = a.size();
		lenb[b] = b.size();
		translate[a] = b;
		translate[b] = a;
	}
	for(int i = 0; i < n; i++)
	{
		string c;
		cin >> c;
		if(lena.count(c))
		{
			if(lenb[translate[c]] < lena[c])
			{
				cout << translate[c] << " ";
			}
			else
			{
				cout << c << " ";
			}
		}
		else
		{
			if(lena[translate[c]] < lenb[c])
			{
				cout << translate[c] << " ";
			}
			else
			{
				cout << c << " ";
			}
		}
	}
	cout << "\n";
	return 0;
}

