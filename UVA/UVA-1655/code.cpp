/*
转化为(a,b,c)的三元组，a*b*c <= n
暴力求解即可
*/
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;

LL ABC(LL n)
{
	LL a = pow(n,0.3334) + 0.5;
	LL b = pow(n,0.5) + 0.5;
	LL count = 0;
	for (LL i = 1; i <= a; ++i)
	{
		for (LL j = i+1; j <= b; ++j)
		{
			LL k = n/i/j - j;
			if(k <= 0) break;
			count += k;
		}
	}
	return count;
}

LL AAB(LL n)
{
	LL a = pow(n,0.5) + 0.5;
	LL count = 0, b;
	for (LL i = 1; i <= a; ++i)
	{
		b = n/i/i;
		if(b <= 0) break;
		if(b >= i) --b;
		count += b;
	}
	return count;
} 

LL solve(LL n)
{
	LL res = pow(n,0.334) + 0.5;
	while(res * res * res > n) --res;
	res += ABC(n) * 6;
	res += AAB(n) * 3;
	return res;
}

int main()
{
	LL n;
	int Case = 0;
	while(scanf("%lld", &n) == 1)
	{
		printf("Case %d: %lld\n", ++Case,solve(n));
	}
	return 0;
} 
