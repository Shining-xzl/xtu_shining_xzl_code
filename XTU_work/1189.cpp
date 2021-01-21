#include <stdio.h>

int main()
{
	int tim;
	int a,b,c,ans,l,m;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c!=1)
		{
			ans=b*c-a;
			m=1-c;
			l=ans%m;
			ans=ans/m;
			if(l==0&&ans>=0)
			{
				if(a==b&&a==0) printf("None\n");
				else printf("%d\n",ans);
			}
			else printf("None\n");
		}
		else
		{
			if(a!=b)printf("None\n");
			else if(a==0) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}

