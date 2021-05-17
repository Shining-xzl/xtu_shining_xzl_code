#include <cstdio>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b)
{	
	if (b == 0LL) return a;
	else return gcd(b,a%b);
} 
int main()
{
	int T,n = 0,k;
	LL a,b,t;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%*d %d",&k);
		a = k+1;
		b = 1LL;
		while(k--) b <<= 1;
		a = b - a;
		t = gcd(b,a);
		a /= t;
		b /= t;
		printf("Case #%d: %lld/%lld\n", ++n,a,b);
	}
	return 0;
} 
