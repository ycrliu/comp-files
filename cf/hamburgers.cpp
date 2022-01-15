#include <bits/stdc++.h>

using namespace std;

int main()
{
	string recipe;
	long long num_bread, num_sausage, num_cheese, price_bread, price_sausage, price_cheese, money;
	cin >> recipe >> num_bread >> num_sausage >> num_cheese >> price_bread >> price_sausage >> price_cheese >> money;
	
	long long bread_per_burger = 0;
	long long sausage_per_burger = 0;
	long long cheese_per_burger = 0;
	for(char c : recipe)
	{
		if(c == 'B')
			bread_per_burger++;
		else if(c == 'S')
			sausage_per_burger++;
		else
			cheese_per_burger++;
	}

	long long lo = 0ll;
	long long hi = 9999999999999ll;
	long long max_burgers_possible = -1ll;
	while(lo <= hi)
	{
		long long X = lo + (hi - lo) / 2; // test number of burgers

		long long bread_money_needed_for_x_burgers = 0ll;
		if(bread_per_burger != 0)
		{
//			bread_money_needed_for_x_burgers = (X - min(num_bread / bread_per_burger, X)) * bread_per_burger * price_bread;
//			   - This expression is wrong because one could be half a burger short of ingredients,
//			     but it treats those missing ingredients as an entire additional burger

			// Calculate burger purely by the number of parts - more precise
			bread_money_needed_for_x_burgers = max(bread_per_burger * X - num_bread, 0ll) * price_bread;
		}

		long long sausage_money_needed_for_x_burgers = 0ll;
		if(sausage_per_burger != 0)
		{
//			sausage_money_needed_for_x_burgers = (X - min(num_sausage / sausage_per_burger, X)) * sausage_per_burger * price_sausage;
			sausage_money_needed_for_x_burgers = max(sausage_per_burger * X - num_sausage, 0ll) * price_sausage;
		}

		long long cheese_money_needed_for_x_burgers = 0ll;
		if(cheese_per_burger != 0)
		{
//			cheese_money_needed_for_x_burgers = (X - min(num_cheese / cheese_per_burger, X)) * cheese_per_burger * price_cheese;
			cheese_money_needed_for_x_burgers = max(cheese_per_burger * X - num_cheese, 0ll) * price_cheese;
		}

		if(money >= bread_money_needed_for_x_burgers + sausage_money_needed_for_x_burgers + cheese_money_needed_for_x_burgers)
		{
			lo = X + 1;
			max_burgers_possible = X;
		}
		else
		{
			hi = X - 1;
		}
	}
	cout << max_burgers_possible << endl;
	return 0;
}

