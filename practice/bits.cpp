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
/*
// Equivalent keywords are
compl 4    // Performs a bitwise not
4 bitor 3  // Performs bitwise or
4 bitand 3 // Performs bitwise and
4 xor 3    // Performs bitwise xor
*/

string bitForm(int x)
{
    // bits are indexed from right to left

    // 1<<k has a '1' in position k (calculated from the right, 0-indexed)
    // and all other bits 0

    // kth bit of a number is one exactly when x&(1<<k) is not 0
    
    // we can iterate over all values of k to print out the bit representation
    // of x
    //
    //
    // the last bit enables us to check the parity of a number.
    // doing (x&1) is the same as x%2==1
    
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

void sets()
{
    int x = 0;
    // x contains the subset of {0, 1, 2, ..., 31} that is {1, 3, 4, 8}


    x |= (1 << 1); // activates 1st bit from right (0-indexed)
    x |= (1 << 3); // activates 3rd bit from right
    x |= (1 << 4);
    x |= (1 << 8);

    // print size of subset
    cout << __builtin_popcount(x) << endl;

    // print subset
    cout << bitForm(x) << endl;

    // print elements of set
    
    for(int i = 0; i <= 31; i++)
    {
        if((x & (1 << i)) > 0) // OR do (x >> i) & 1
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void set_ops()
{
    // Operations:
    // 1) intersection: a & b
    // 2) union:        a | b
    // 3) complement:   ~a
    // 4) difference:   a & (~b)

    // create set {1, 3, 4, 8}
    // create individual sets {1}, {3}, {4}, {8}, and union them
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);

    // create set {3, 6, 8, 9}
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);

    int z = x | y;

    // 1 3 4 6 8 9 (size 6)
    cout << __builtin_popcount(z) << endl;
}

void iterate_through_subsets(int k)
{
    // goes through subsets of {0, 1, ..., n - 1}
    // an on bit means that value is in the subset
//    for(int i = 0; i < (1 << n); i++)
//    {
//    }
//
//    // goes through subsets of {0, 1, ..., n - 1} of size k
//    for(int i = 0; i < (1 << n); i++)
//    {
//        if(__builtin_popcount(i) == k)
//        {
//
//        }
//    }

}

int hammingDist(int a, int b)
{
    // hamming distance between two bit strings of equal length is the number of
    // positions where the strings differ

    // if the strings are small, store them as integers and use bit operations

    return __builtin_popcount(a ^ b);

    // xor creates a bit string with 1s where a and b differ; then count the 1s
}

void countSubgrids()
{
    // nxn subgrid; each square is either black or white
    // let black=1, white=0
    // count the number of subgrids whose corners are black

    // Approach 1:
    // go through all pairs (a, b) of rows: (O(n^2))
    // for each pair (a, b), calculate the number of columns that contain
    // a black square in both rows (O(n))
    // then the answer is count*(count-1)/2 b/c we  can choose any two of them
    // to form a subgrid

//    int count = 0;
//    // go through columns
//    for (int i = 0; i < n; i++) {
//        if (color[a][i] == 1 && color[b][i] == 1) count++;
//    }


    // Approach 2:
    // divide the grid into blocks of columns such that each block consists of N
    // consecutive columns
    // then, each row is stored in a list of N-bit numbers that describe the color
    // of the squares.
    // now we can process N columns at the same time using bit operations.
    // color[y][k] represents a block of N colors as bits

    //    given row pairs (a, b):
//    int count = 0;
//
//    // go through column blocks
//    for(int i = 0; i <= n / N; i++)
//    {
//        count += __builtin_popcount(color[a][i] & color[b][i]);
//    }
}

void dp()
{
    // bit operations help us implement DP algorithms whose states contain
    // subsets of elements by storing such states as integers.


    // 1)
    // Given prices of k products over n days (n x k matrix)
    // want to buy each product exactly once.
    // allowed to buy at most one product in a day (n >= k)
    // what is the min total price
    
    // Given info: let price[x][d] denote the price of product x on day d
    // 
    // let total(S, d) denote the minimum total price for buying a subset S of
    // products by day d

    int dp[1 << k][n];

    // iterate over all products on day 1
    for(int i = 0; i < k; i++)
    {
        // 1 << i is a subset containing only i
        dp[1 << i][0] = price[i][0];
    }

    for(int i = 1; i < n; i++)
    {
        // iterate over all subsets
        for(int s = 0; s < (1 << k); s++)
        {
            // don't buy an item
            dp[s][i] = dp[s][i - 1];

            // buy an item x - the product that minimizes the cost on day i
            for(int x = 0; x < k; x++)
            {
                if((s & (1 << x)) != 0) // x is in the subset s
                {
                    // remove x from the subset s: s ^ (1 << x)
                    // xor-ing s and 1<<x (both bit forms have 1 in the x-th position)
                    // will deactivate the xth bit and make it 0, thus removing
                    // x from s
                    dp[s][i] = min(dp[s ^ (1 << x)][i - 1] + price[x][s], dp[s][i]);
                }
            }
        }
    }
}
int main()
{

//    the << operator is 0-indexed
//    cout << bitForm(1 << 0) << endl;
//    cout << bitForm(1 << 1) << endl;
//    cout << bitForm(1 << 2) << endl;
//    cout << bitForm(1 << 3) << endl;
//    cout << bitForm(1 << 4) << endl;

    // 1
//    for(int i = 1; i <= 10; i++)
//    {
//        cout << bitForm(i) << endl;
//    }

//    2
//    sets();

//    3
//    set_ops();

    // xor:
    // 0^0 = 1^1 = false = 0
    // 1^0 = true = 1

    return 0;
}

