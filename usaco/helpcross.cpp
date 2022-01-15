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

pair<int, int> cow[20005];

int main()
{
	ifstream cin("helpcross.in");
	ofstream cout("helpcross.out");
	int c, n;
	cin >> c >> n;
	multiset<int> ct;
	for(int i = 0; i < c; i++)
	{
		int t;
		cin >> t;
		ct.insert(t);
	}
	// maximize # of usable cow intervals by sorting by finishing time
	for(int i = 0; i < n; i++)
		cin >> cow[i].second >> cow[i].first;
	sort(cow, cow + n);
	int pairs = 0;
	for(int i = 0; i < n; i++)
	{
		auto it = ct.lower_bound(cow[i].second);
		if(it != ct.end() && *it <= cow[i].first) // verify chicken is within cow's interval
		{
			pairs++;
			ct.erase(it);
		}
	}
	cout << pairs << endl;
	return 0;
}

