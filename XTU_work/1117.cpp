#include <cstdio>
using namespace std;
int ans[100002][10];
int k[100002];

void prime()
{
	int a,b,c,d,e,temp;
	for(a=0;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=0;c<=9;c++)
				for(d=0;d<=9;d++)
					for(e=0;e<=9;e++)
					{
						temp=a*10000+b*1000+c*100+d*10+e;
						k[temp]=(a*a+b*b+c*c+d*d+e*e)%10;
					}
	k[100000]=1;
	for(a=1;a<=100000;a++)
	{
		for(b=0;b<=9;b++)
			ans[a][b]=ans[a-1][b];
		ans[a][k[a]]++;
	}
}

int main()
{
	int tim,a,b,n;
	prime();
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d%d",&a,&b,&n);
		printf("%d\n",ans[b][n]-ans[a-1][n]);
	}
	return 0;
}
