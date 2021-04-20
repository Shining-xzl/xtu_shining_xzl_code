/*
思维+预处理
大数据
好题一道
数学证明
gcd(a,b) <= a-b <= a^b
*/

#include <cstdio>
using namespace std;
typedef unsigned long long ll;
typedef unsigned int Uint;
const Uint lim = 30000000;
ll ans[lim+3];

int main()
{	
	for (Uint i = 1; i <= lim; ++i)
		for (Uint j = (i<<1); j <= lim; j+=i)
		{
			if((i^j)==(j-i)) ++ans[j];
		}
	for (Uint i = 1; i <= lim; ++i)
		ans[i] += ans[i-1];
	Uint T,n;
	scanf("%u", &T);
	for (Uint i = 1; i <= T; ++i)
	{
		scanf("%u", &n);
		printf("Case %u: %llu\n", i,ans[n]);
	}
	return 0;
} 
