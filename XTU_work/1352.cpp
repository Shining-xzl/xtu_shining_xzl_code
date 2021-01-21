#include <cstdio>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int time;
	scanf("%d",&time);
	long long a,b,i,k;
	while(time--)
	{
		scanf("%I64d%I64d",&a,&b);
		while(1)
		{
			i=b/a;
			while(i*a<b) i++;
			a=a*i-b;
			b=b*i;
			k=gcd(a,b);
			a/=k;
			b/=k;
			printf("%I64d",i);
			if(a==0) break;
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
