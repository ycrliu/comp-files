/*
ID: robertl8
LANG: C++11
TASK: pprime
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

//https://stackoverflow.com/questions/4424374/determining-if-a-number-is-prime
long long power(int a, int n, int mod)
{
 long long power=a,result=1;
 while(n)
 {
  if(n&1) 
   result=(result*power)%mod;
  power=(power*power)%mod;
  n>>=1;
 }
 return result;
}
bool witness(int a, int n)
{
 int t,u,i;
 long long prev,curr;
 u=n/2;
 t=1;
 while(!(u&1))
 {
  u/=2;
  ++t;
 }
 prev=power(a,u,n);
 for(i=1;i<=t;++i)
 {
  curr=(prev*prev)%n;
  if((curr==1)&&(prev!=1)&&(prev!=n-1)) 
   return true;
  prev=curr;
 }
 if(curr!=1) 
  return true;
 return false;
}
inline bool isprime( int number )
{
 if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return (false);
 if(number<1373653)
 {
  for( int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return (false);
  return true;
 }
 if(number < 9080191)
 {
  if(witness(31,number)) return false;
  if(witness(73,number)) return false;
  return true;
 }
 if(witness(2,number)) return false;
 if(witness(7,number)) return false;
 if(witness(61,number)) return false;
 return true;
 /*WARNING: Algorithm deterministic only for numbers < 4,759,123,141 (unsigned int's max is 4294967296)
   if n < 1,373,653, it is enough to test a = 2 and 3.
   if n < 9,080,191, it is enough to test a = 31 and 73.
   if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
   if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
   if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
   if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/
}


vector<string> pals;
int num(string s)
{
	return !s.size() ? 0 : (s[s.size() - 1] - '0') + 10 * num(s.substr(0, s.size() - 1));
}

void recur(string s, int i, int len)
{
	//1
	//121
	//1221
	if(i == len || ((len&1) ? i == len/2+1 : i == len/2))
	{
		if(i != len)
		{
			for(int j = (len&1) ? i - 2 : i - 1; ~j; --j)
				s += s[j];
		}
		pals.push_back(s);
//		cout << "a " << s << " len " << len << " i " << i << endl;

	}
	else
		for(int j = (!i) ? 1 : 0; j <= 9; ++j)
		{
			string add = "";
			add += (j + '0');
	//		cout << "b " << s + add << endl;
			recur(s + add, i + 1, len);
		}
}

int main()
{
#ifndef HOME
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;

	pals.push_back("5");
	pals.push_back("7");
	int pl1 = max(2, (int)(trunc(log10(a)) + 1)), pl2 = trunc(log10(b)) + 1;
	for(; pl1 <= pl2; ++pl1)
	{
		recur("", 0, pl1);
	}
	for(int i = 0; i < pals.size(); ++i)
	{
		int n = num(pals[i]);
		if(isprime(n) && n >= a && n <= b)
			cout << n << endl;
	}
	return 0;
}

