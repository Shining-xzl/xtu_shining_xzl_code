#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int time,n,m,a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		a=2*n*m;
		b=(n+m)*(n+m-1);
		if(b==0) 
		{
			printf("0\n");
			continue;
		}
		n=gcd(a,b);
		a/=n;
		b/=n;
		printf("%d",a);
		if(b!=1) printf("/%d",b);
		printf("\n");
	}
	return 0;
}
