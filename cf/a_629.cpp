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

const int MAX_N = 100000;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long a, b;
		cin >> a >> b;
		if(a % b == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << b * (a / b + 1) - a << endl;
		}
	}
	return 0;
}

