#include <cstdio>

using namespace std;

typedef long long LL;
const LL MOD=1e9+7;

LL x,y;
void exgcd(LL a,LL b)
{
	if(b==0LL)
	{
		x=1LL;
		y=0LL;
		return;
	}
	exgcd(b,a%b);
	LL temp = y;
	y = x - (a/b)*y;
	x = temp;
}

int main()
{
	exgcd(6,MOD);
	if(x < 0) x += MOD;
	LL n,ans = 0,temp;
	scanf("%lld",&n);
	// ans = n*n*n + 3*n*n + 2*n;
	// ans /= 6;

	// if( n&1 )
	// {
	// 	n>>=1;
	// 	temp = 4*n*n*n + 9*n*n + 5*n;
	// 	temp /= 6;
	// 	ans += temp;
	// }
	// else
	// {
	// 	n>>=1;
	// 	temp = 4*n*n*n + 3*n*n - n;
	// 	temp /= 6;
	// 	ans += temp;
	// }

	ans = n*n%MOD*n + n*n%MOD*3 + 2*n%MOD;
	ans %= MOD;
	ans = ans*x%MOD;
	if( n&1 )
	{
		n>>=1;
		temp = 4*n%MOD*n%MOD*n%MOD + 9*n%MOD*n%MOD + 5*n%MOD;
		temp %= MOD;
		temp = temp*x%MOD;

	}
	else
	{
		n>>=1;
		temp = 4*n%MOD*n%MOD*n%MOD + 3*n%MOD*n%MOD - n;
		temp %= MOD;
		temp = temp*x%MOD;
		
	}
	ans = ans + temp;
	ans %= MOD;

	printf("%lld\n", ans);
	return 0;
}