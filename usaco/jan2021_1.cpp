#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	string key, hum;
	cin >> key >> hum;
	int num_needed = 1;
	for(int i = 0; i + 1 < hum.size(); i++)
	{
		num_needed += (find(key.begin(), key.end(), hum[i + 1]) <= find(key.begin(), key.end(), hum[i]));
	}
	cout << num_needed << endl;
	return 0;
}

