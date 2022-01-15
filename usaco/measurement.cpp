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

struct entry
{
	int day;
	int delta;
	string name;
};

int main()
{
	ifstream cin("measurement.in");
	ofstream cout("measurement.out");

	int n;
	cin >> n;
	vector<entry> entries(n);
	for(int i = 0; i < n; i++)
	{
		cin >> entries[i].day >> entries[i].name >> entries[i].delta;
	}
	sort(entries.begin(), entries.end(), [](entry e, entry f) {
			return e.day < f.day;
	});

	bool bessie_top = true;
	bool elsie_top = true;
	bool mildred_top = true;
	int bessie = 7;
	int elsie = 7;
	int mildred = 7;
	int changes = 0;
	for(int i = 0; i < n; i++)
	{
		if(entries[i].name == "Bessie")
			bessie += entries[i].delta;
		else if(entries[i].name == "Elsie")
			elsie += entries[i].delta;
		else
			mildred += entries[i].delta;

		int new_top = max(bessie, max(elsie, mildred));
		bool bessie_now = bessie == new_top;
		bool elsie_now = elsie == new_top;
		bool mildred_now = mildred == new_top;

		if(bessie_now != bessie_top || elsie_now != elsie_top || mildred_now != mildred_top)
			changes++;

		bessie_top = bessie_now;
		elsie_top = elsie_now;
		mildred_top = mildred_now;
	}
	cout << changes << endl;
	return 0;
}

