#include <cstdio>

int main()
{
	int a,b,c,l,r;
	int tim,ans;
	scanf("%d",&tim);
	while(tim--)
	{
		ans=-1;
		scanf("%d%d",&a,&b);
		if(a>b) c=b,b=a,a=c;
		l=b-a;
		r=a+b;
		for(c=l+1;c<r;c++)
			if(c*c+a*a==b*b||a*a+b*b==c*c)
			{
				ans=c;break;
			}
		if(ans==-1)
			printf("None\n");
		else printf("%d\n",ans);
	}
}
