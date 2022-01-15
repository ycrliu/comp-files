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
ll to_bin(int num)
{
	return num == 0 ? 0 : 10 * to_bin(num / 2) + (num % 2);
}
int main()
{
	for(int i = 1; i <= 18; i++)
	{
		cout << (1 << i) << " " << (to_bin(1 << i)) << endl;
	}
	return 0;
}

