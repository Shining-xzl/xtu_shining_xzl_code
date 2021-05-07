#include <cstdio>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b)
{
	if(b == 0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int n,count,count1;
	LL a,b,k,x;
	while(scanf("%d", &n) == 1)
	{
		a = 0;
		b = 1;
		for (int i = 0; i < n; ++i)
		{
			a = a * (n - i) + b * n;
			b = b * (n - i);
			k = gcd(a,b);
			a /= k;
			b /= k;
		}
		k = a / b;
		a = a % b;
		if(a == 0) printf("%lld\n", k);
		else
		{
			count = count1 = 0;
			x = k;
			while(x > 0)
			{
				x /= 10;
				++count;
			}
			for (int i = 0; i <= count; ++i)
				putchar(' ');
			printf("%lld\n", a);
			printf("%lld ", k);
			x = b;
			while(x > 0)
			{
				x /= 10;
				++count1;
			}
			for (int i = 0; i < count1; ++i)
				putchar('-');
			putchar('\n');
			for (int i = 0; i <= count; ++i)
				putchar(' ');
			printf("%lld\n", b);
		}
	}
	return 0;
} 
