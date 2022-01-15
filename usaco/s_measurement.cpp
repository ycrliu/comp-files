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
using ll = long long;

struct entry
{
	int day, cow, delta;
};

int main()
{
//	ifstream cin("measurement.in");
//	ofstream cout("measurement.out");

	int n, g;
	cin >> n >> g;
	vector<entry> entries(n);
	map<int, pair<ll, bool>> output;
	for(int i = 0; i < n; i++)
	{
		cin >> entries[i].day >> entries[i].cow >> entries[i].delta;
		output[entries[i].cow].first = 0;
		output[entries[i].cow].second = true;
	}
	sort(entries.begin(), entries.end(), [](entry e, entry f) {
		return e.day < f.day;
	});
	ll top = 0;
	int changes = 0;
	for(int i = 0; i < n; i++)
	{
		int cur = entries[i].cow;
		output[cur].first += entries[i].delta;
		if(output[cur].first > top)
		{
			bool other_cow_demoted = false;
			for(map<int, pair<ll, bool>>::iterator it = output.begin(); it != output.end(); it++)
			{
				if(it->second.first == top)
				{
					other_cow_demoted = true;
					it->second.second = false;
				}
			}
			if(!output[cur].second || other_cow_demoted)
			{
				output[cur].second = true;
				changes++;
			}
			top = output[cur].first;
		}
		else if(output[cur].first == top)
		{
			changes++;
			output[cur].second = true;
		}
		else if(output[cur].first < top && output[cur].second)
		{
			ll max_output = LLONG_MIN;
			for(auto out : output)
			{
				if(out.first != cur)
					max_output = max(out.second.first, max_output);
			}
			if(output[cur].first <= max_output)
			{
				changes++;
				if(output[cur].first < max_output)
					output[cur].second = false;
				for(map<int, pair<ll, bool>>::iterator it = output.begin(); it != output.end(); it++)
				{
					if(it->second.first == max_output)
						it->second.second = true;
				}
			}
			top = max(max_output, output[cur].first);
		}
	}
	cout << changes << endl;
	return 0;
}

