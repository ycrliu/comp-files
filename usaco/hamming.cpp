/*
ID: robertl8
LANG: C++11
PROB: hamming
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
#include <bitset>

using namespace std;

//int hamming_dist(int v1, int v2, int b)
//{
//	int dist = 0;
//	for(int i = 0; i < b; i++)
//		if((v1 & (1 << i)) ^ (v2 & (1 << i)))
//			dist++;
//	return dist;
//}

int main()
{
	ifstream cin("hamming.in");
	ofstream cout("hamming.out");

	int n, b, d;
	cin >> n >> b >> d;
	vector<int> codewords;
	int cur = 0;
	while(codewords.size() < n)
	{
		bool ok = true;
		for(int cw : codewords)
		{
			if(__builtin_popcount(cur ^ cw) < d)
			{
				ok = false;
				break;
			}
		}
		if(ok)
			codewords.push_back(cur);
		cur++;
	}
	for(int i = 0; i < n; i++)
		cout << codewords[i] << ((i % 10 == 9 || i == n - 1) ? "\n" : " ");
	return 0;
}

