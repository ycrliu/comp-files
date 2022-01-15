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

struct pt
{
	int x, y;
	bool remove;
};

bool sort_by_x(pt e, pt f)
{
	return e.x < f.x;
}

bool sort_by_y(pt e, pt f)
{
	return e.y < f.y;
}

const int MAXA = 2e9;
int n;
pt a[50005];

ll get_area(vector<int> ignore)
{
	int maxX = -1;
	int minX = 40005;
	int maxY = -1;
	int minY = 40005;
	for(int i = 0; i < n; i++)
	{
		if(find(ignore.begin(), ignore.end(), i) == ignore.end())
		{
			maxX = max(a[i].x, maxX);
			minX = min(a[i].x, minX);
			maxY = max(a[i].y, maxY);
			minY = min(a[i].y, minY);
		}
	}
	return (maxX - minX) * ((ll)(maxY - minY));
}

int main()
{
	ifstream cin("reduce.in");
	ofstream cout("reduce.out");
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].remove = false;
	}
	sort(a, a + n, sort_by_x);
	for(int i = 0; i < 3; i++)
	{
		a[i].remove = true;
		a[n - 1 - i].remove = true;
	}
	sort(a, a + n, sort_by_y);
	for(int i = 0; i < 3; i++)
	{
		a[i].remove = true;
		a[n - 1 - i].remove = true;
	}
	vector<int> removable;
	for(int i = 0; i < n; i++)
		if(a[i].remove == true)
			removable.push_back(i);
	ll area = MAXA;
	for(int mask = 0; mask < (1 << ((int)removable.size())); mask++)
	{
		if(__builtin_popcount(mask) != 3)
			continue;
		vector<int> ignore;
		for(int i = 0; i < (int)removable.size(); i++)
			if((mask & (1 << i)) != 0)
				ignore.push_back(removable[i]);
		area = min(get_area(ignore), area);
	}
	cout << area << endl;
	return 0;
}

