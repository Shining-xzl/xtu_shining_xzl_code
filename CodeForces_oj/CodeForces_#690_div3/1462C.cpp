#include <cstdio>
#include <cstring>
using namespace std;

bool f[10];

bool dfs(int x,int now)
{
	if(x<=now&&f[x]==0)
	{
		printf("%d",x);
		return 1;
	}
	else
	{
		for(int i=now;i>0;i--)
		{
			if(!f[i]&&x>=i)
			{
				f[i]=1;
				if(dfs(x-i,i-1))
				{
					printf("%d",i);
					return 1;
				}
				f[i]=0;
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int time,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		if(!dfs(n,9))
		{
			printf("-1\n");
		}
		else printf("\n");
	}
	return 0;
}