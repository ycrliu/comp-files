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

int main()
{
	ifstream cin("lostcow.in");
	ofstream cout("lostcow.out");
	int x, y;
	cin >> x >> y;
	bool positive = true;
	int nx = 1;
	int pos = x;
	int dist = 0;
	while(true)
	{
		int newpos = x + (positive ? 1 : -1) * nx;
		if((newpos > y && y > x) || (newpos < y && y < x) || (newpos == y))
		{
			dist += abs(y - pos);
			break;
		}
		else
		{
			dist += abs(newpos - pos);
		}
		pos = newpos;
		positive = !positive;
		nx *= 2;
	}
	cout << dist << endl;
	return 0;
}

