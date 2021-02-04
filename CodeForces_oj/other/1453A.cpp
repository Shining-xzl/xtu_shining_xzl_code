#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	int n,m,ans=0,x;
	int k[103];
	while(time--)
	{
		ans=0;
		memset(k,0,sizeof(k));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),k[x]=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if(k[x]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}