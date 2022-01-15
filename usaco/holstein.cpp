/*
ID: robertl8
LANG: C++11
PROB: holstein
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

int v, g;
int req[26];
int feed[16][26];

bool cur_ok(vector<int>& feeds)
{
	vector<int> cur_sum(v, 0);
	for(int i = 0; i < feeds.size(); i++)
		for(int j = 0; j < v; j++)
			cur_sum[j] += feed[feeds[i]][j];
	for(int i = 0; i < v; i++)
		if(cur_sum[i] < req[i])
			return false;
	return true;
}

bool is_smaller(vector<int>& a, vector<int>& b)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] < b[i])
			return true;
	return false;
}

int main()
{
	ifstream cin("holstein.in");
	ofstream cout("holstein.out");

	cin >> v;
	for(int i = 0; i < v; i++)
		cin >> req[i];
	cin >> g;
	for(int i = 0; i < g; i++)
		for(int j = 0; j < v; j++)
			cin >> feed[i][j];
	
	vector<int> ans;
	for(int i = 0; i < (1 << g); i++)
	{
		vector<int> feeds;
		for(int j = 0; j < g; j++)
			if((i & (1 << j)) != 0)
				feeds.push_back(j);
		if(cur_ok(feeds))
		{
			if(ans.empty() || feeds.size() < ans.size())
				ans = feeds;
			else if(feeds.size() == ans.size())
				if(is_smaller(feeds, ans))
					ans = feeds;
		}
	}
	
	cout << ans.size() << " ";
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");

	return 0;
}
