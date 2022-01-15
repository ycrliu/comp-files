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
using ll = long long;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<pair<int, bool>> gaps; //true=start/end gap, discard smaller half
	//start->first
	//start|xxxxxxxx
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
		{
			gaps.push_back({i + 1, true});
			break;
		}
	}
	//last->end
	//xxxxxx|end
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '1')
		{
			gaps.push_back({n - i, true});
			break;
		}
	}
	// non endpoint segments
	int last_seg_start = -1;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0' && last_seg_start == -1)
			last_seg_start = i;
		if(s[i] == '1' && last_seg_start != -1)
		{
			gaps.push_back({i - last_seg_start + 1, false});
			last_seg_start = -1;
		}
	}
	sort(gaps.rbegin(), gaps.rend());
	for(int it = 0; it < 2; it++)
	{
		auto cur_gap = gaps.front();
		gaps.erase(gaps.begin());
		if(cur_gap.first % 2 == 0)
		{
			gaps.push_back({cur_gap.first / 2, false});
			gaps.push_back({cur_gap.first / 2, false});
		}
		else
		{
			gaps.push_back({cur_gap.first / 2 + 1, false});
			if(!cur_gap.second)
				gaps.push_back({cur_gap.first / 2, false});
		}
	}
	sort(gaps.begin(), gaps.end());
	cout << gaps.front().first << endl;
	return 0;
}

