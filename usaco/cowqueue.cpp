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

array<int, 2> cow[105];

int main()
{
	ifstream cin("cowqueue.in");
	ofstream cout("cowqueue.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> cow[i][0] >> cow[i][1];
	}
	sort(cow, cow + n);
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		t = max(cow[i][0], t);
		t += cow[i][1];
	}
	cout << t << endl;
	return 0;
}

