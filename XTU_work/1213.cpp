#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int time,n,m,k;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		n=n*(n-1)*(n-2);
		if(m<3) m=0;
		else m=m*(m-1)*(m-2);
		k=gcd(n,m);
		n/=k;
		m/=k;
		if(m==0) printf("0\n");
		else 
		{
			printf("%d",m);
			if(n!=1) printf("/%d",n);
			printf("\n");
		}
	}
	return 0;
}
