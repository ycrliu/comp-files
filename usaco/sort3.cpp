/*
ID: robertl8
LANG: C++11
PROB: sort3
*/
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

int have[1005];
int want[1005];

int main()
{
	ifstream cin("sort3.in");
	ofstream cout("sort3.out");

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> have[i];
		want[i] = have[i];
	}
	sort(want, want + n);

	int ans = 0;

	// Direct swaps
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(have[i] != want[i] && have[j] != want[j] && have[i] == want[j] && have[j] == want[i])
			{
				ans++;
				swap(have[i], have[j]);
			}
		}
	}

	// Triples - need 2 swaps to correct each one
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(have[i] != want[i])
			count++;
	}
	ans += count / 3 * 2;

	cout << ans << endl;
	return 0;
}

