#include <cstdio>
using namespace std;
int n;
int pre[1003];
int nex[1003];
int s[1003];

int main()
{
	int i,con,ans;
	while(scanf("%d",&n)==1)
	{
		con=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			pre[i]=i-1;
			nex[i]=i+1;
		}
		i=1;
		while(1)
		{
			while(1)
			{
				if(s[i]<=con)
				{
					con++;
					nex[pre[i]]=nex[i];
					pre[nex[i]]=pre[i];
					s[i]=1003;
				}
				if(nex[i]>n) break;
				i=nex[i];
			}
			if(con==n) break;
			ans++;
			while(1)
			{
				if(s[i]<=con)
				{
					con++;
					pre[nex[i]]=pre[i];
					nex[pre[i]]=nex[i];
					s[i]=1003;
				}
				if(pre[i]<1) break;
				i=pre[i]; 
			}
			if(con==n) break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
