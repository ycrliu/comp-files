#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>
#include <cassert>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;
string bitForm(int x)
{
    // bits are indexed from right to left

    // 1<<k has a '1' in position k (calculated from the right, 0-indexed)
    // and all other bits 0

    // kth bit of a number is one exactly when x&(1<<k) is not 0
    
    // we can iterate over all values of k to print out the bit representation
    // of x
    
    string res;
    // go from 31 to 0 to go from right to left in x
    for(int i = 31; i >= 0; i--)
    {
        if((x & (1 << i)) > 0)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
    }

    return res;

}
int main()
{
    cout << bitForm(1<<2) << endl;
    return 0;
}

