#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time,n,x,a,b,temp;
	double r,c;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&x);
		a=x-1;
		b=n-x;
		if(a>b) x=a,a=b,b=x;
//		printf("%d %d\n",a,b);
		if(n==1) printf("ma la se mi no.1!\n");
		else if(a==0||b==0||a==b) printf("yo xi no forever!\n");
		else
		{
			r=(sqrt(5.0)+1)/2;
			c=(double)(b-a);
			temp=(int)(r*c);
			if(temp==a) printf("ma la se mi no.1!\n");
			else printf("yo xi no forever!\n");
		}
	}
	return 0;
 } 
