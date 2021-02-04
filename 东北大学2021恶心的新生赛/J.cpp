#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int dis[302][302];
int n,m;
int num[302];
int main()
{
//	freopen("in.txt","r",stdin);
	memset(dis,INF,sizeof(dis));
	int a,b,c,pre,now,ans=INF,xnum;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=c;
		dis[b][a]=c;
	}
	scanf("%d",&m);
	while(m--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&xnum);
		pre=0;
		c=0;
		while(xnum--)
		{
			scanf("%d",&now);
			
			num[now]++;
			if(c<INF)
				c+=dis[now][pre];
			pre=now;
		}
		if(c<INF)
			c+=dis[now][0];
		for(int i=1;i<=n;i++)
			if(num[i]!=1) c=INF;
		if(c<ans) ans=c; 
	}
	if(ans<INF) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
} 
