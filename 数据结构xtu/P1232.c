#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,c=0,cnt;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=m;j++)
			if(i%j==0) cnt++;
		if(cnt&1)
		{
			if(c==1) putchar(',');
			printf("%d",i);
			c=1;
		}
	}
	return 0;
}