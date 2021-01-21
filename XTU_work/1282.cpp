#include <cstdio>
using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int time;
	scanf("%d",&time);
	__int64 n,m,k;
	int a,b,i;
	while(time--)
	{
		scanf("%d%d",&a,&b);
		n=1;
		m=a;
		for(i=a+1;i<=b;i++)
		{
			n=n*i+m;
			m=m*i;
			k=gcd(n,m);
			n/=k;
			m/=k;
		}
		printf("%I64d",n);
		if(m>1) printf("/%I64d\n",m);
	}
	return 0;
}
