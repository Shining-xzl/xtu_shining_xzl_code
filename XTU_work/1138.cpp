#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

void ans(int &n,int &m)
{
	int a,b,k;
	if(m==0) 
	{
		printf("1\n");
		return;
	}
	a=m*(m-1);
	b=n*(n-1);
	a=b-a;
	if(a==0)
	{
		printf("0\n");
		return;
	}
	k=gcd(a,b);
	a/=k;
	b/=k;
	printf("%d",a);
	if(b>1) printf("/%d",b);
	printf("\n");
	return;
}

int main()
{
	int time,n,m;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		ans(n,m);
	}
	return 0;
}
