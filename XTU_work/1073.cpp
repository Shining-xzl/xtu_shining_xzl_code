#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c,p;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	{
		p=a;
		a=b;
		b=p;
	}
	if(a<c) 
	{
		p=a;
		a=c;
		c=p;
	}
	if(b<c)
	{
		p=b;
		b=c;
		c=p;
	}
	printf("%d %d",a,c);
	return 0;
}
