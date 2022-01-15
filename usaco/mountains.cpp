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

struct peak
{
	int x, y;
};

peak p[100005];

// checks if mountain b is hidden by mountain a given that a has a higher peak than b
bool hidden(peak a, peak b)
{
	return a.x + a.y >= b.x + b.y && a.x - a.y <= b.x - b.y;
}

int main()
{
	ifstream cin("mountains.in");
	ofstream cout("mountains.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + n, [](peak a, peak b) {
		return a.y < b.y;
	});
	int visible = 0;
	for(int i = 0; i < n; i++)
	{
		bool vis = true;
		for(int j = i + 1; j < n; j++)
		{
			if(hidden(p[j], p[i]))
			{
				vis = false;
				break;
			}
		}
		if(vis)
			visible++;
	}
	cout << visible << endl;
	return 0;
}

