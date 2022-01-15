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

int main()
{
	int n;
	cin >> n;
	
	vector<int> p1, p2;
	// assume front of array is top of stack

	int k1;
	cin >> k1;
	for(int i = 0, k; i < k1; i++)
	{
		cin >> k;
		p1.push_back(k);
	}
	int k2;
	cin >> k2;
	for(int i = 0, k; i < k2; i++)
	{
		cin >> k;
		p2.push_back(k);
	}

	int turns = 0;
	bool works = true;
	while(!p1.empty() && !p2.empty())
	{
		int c1 = p1.front();
		p1.erase(p1.begin());
		int c2 = p2.front();
		p2.erase(p2.begin());
		if(c1 > c2)
		{
			p1.push_back(c2);
			p1.push_back(c1);
		}
		else if(c2 > c1)
		{
			p2.push_back(c1);
			p2.push_back(c2);
		}
		turns++;
		if(turns > 9000000)
		{
			works = false;
			break;
		}
	}
	if(!works)
	{
		cout << -1 << endl;
	}
	else if(!p1.empty())
	{
		cout << turns << " " << 1 << endl;
	}
	else
	{
		cout << turns << " " << 2 << endl;
	}
	return 0;
}

