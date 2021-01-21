#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int time;
	int n,m,k,x,y,numc,numl;
	bool c[102],l[102];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&m,&n,&k);
		numc=0;
		numl=0;
		memset(c,0,sizeof(c));
		memset(l,0,sizeof(l));
		while(k--)
		{
			scanf("%d%d",&x,&y);
			if(c[x]==0) 
			{
				c[x]=1;
				numc++;
			}
			if(l[y]==0)
			{
				l[y]=1;
				numl++;
			} 
		}
		printf("%d\n",n*(m-numc)+m*(n-numl)-(m-numc)*(n-numl));
		
	}
	return 0;
}
