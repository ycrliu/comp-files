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

int x[105];
int to[105];
int receive[105];

int main()
{
	ifstream cin("hoofball.in");
	ofstream cout("hoofball.out");

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x + n);
//	if(n == 1)
//	{
//		cout << "1\n";
//		return 0;
//	}
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
			to[i] = i + 1;
		else if(i == n - 1)
			to[i] = i - 1;
		else
			to[i] = x[i + 1] - x[i] < x[i] - x[i - 1] ? i + 1 : i - 1;
		receive[to[i]]++;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(!receive[i])
			count++;
		if(i + 1 < n && to[i] == i + 1 && to[i + 1] == i && receive[i] == 1 && receive[i + 1] == 1)
			count++;
	}
	cout << count << endl;
	return 0;
}

