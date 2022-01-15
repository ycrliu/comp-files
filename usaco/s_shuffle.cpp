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
#include <stack>

using namespace std;

int a[100005];
int receives[100005];

int main()
{
	ifstream cin("shuffle.in");
	ofstream cout("shuffle.out");

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		receives[a[i]]++;
	}
	stack<int> q;
	int emptied = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!receives[i])
		{
			q.push(i);
			emptied++;
		}
	}
	while(!q.empty())
	{
		int feeder = q.top();
		q.pop();
		int check = a[feeder];
		receives[check]--;
		if(!receives[check])
		{
			q.push(check);
			emptied++;
		}
	}
	cout << n - emptied << endl;
	return 0;
}

