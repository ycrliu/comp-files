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
#include <climits>

using namespace std;

int main()
{
	ifstream cin("pails.in");
	ofstream cout("pails.out");

	int x, y, m;
	cin >> x >> y >> m;
	int maxFill = 0;
	for(int xFill = 0; xFill * x <= m; xFill++)
	{
		for(int yFill = 0; yFill * y + xFill * x <= m; yFill++)
		{
			maxFill = max(xFill * x + yFill * y, maxFill);
		}
	}
	cout << maxFill << endl;
	return 0;
}

