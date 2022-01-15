#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N = 100000;
ll num_rounds_wanted[MAX_N + 1];

// Finds the number of rounds of supervision that the number of rounds we're currently testing allows for,
// and makes sure no one is unable to play their desired number of rounds
bool checkSufficiencyOfNumRounds(ll num_rounds, int numPlayers)
{
	ll num_possible_supervisor_rounds = 0;
	for(int i = 0; i < numPlayers; i++)
	{
		ll extra_rounds = num_rounds - num_rounds_wanted[i];
		if(extra_rounds < 0)
		{
			return false;
		}
		num_possible_supervisor_rounds += extra_rounds;
	}
	return num_possible_supervisor_rounds >= num_rounds;
}

int main()
{
	int numPlayers;
	cin >> numPlayers;
	for(int i = 0; i < numPlayers; i++)
	{
		cin >> num_rounds_wanted[i];
	}

	sort(num_rounds_wanted, num_rounds_wanted + numPlayers);

	ll lo = 0ll;
	ll hi = static_cast<long long>(1e14); // approximately 10^5 * 10^9 ?
	ll min_rounds_needed = -1;
	while(lo <= hi)
	{
		ll test_num_rounds = lo + (hi - lo) / 2;
		if(checkSufficiencyOfNumRounds(test_num_rounds, numPlayers))
		{
			min_rounds_needed = test_num_rounds;
			hi = test_num_rounds - 1;
		}
		else
		{
			lo = test_num_rounds + 1;
		}
	}
	cout << min_rounds_needed << endl;
	return 0;
}

