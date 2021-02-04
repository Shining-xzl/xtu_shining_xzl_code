#include <cstdio>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	int s[504],n,ans,temp,pp;
	bool flag;
	scanf("%d",&time);
	s[501]=0;
	while(time--)
	{
		flag=1;
		ans=0;
		scanf("%d%d",&n,&s[0]);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=n-1;i>0;i--)
		{
			if(s[i]>s[i+1])
			{
				temp=501;
				for(int j=i-1;j>=0;j--)
				{
					if(s[j]<s[i]&&s[j]<=s[i+1])
					{
						if(s[i]-s[j]<s[i]-s[temp])
							temp=j;
					}
				}
				if(temp==501)
				{
					flag=0;
					break;
				}
				else
				{
					ans++;	
					pp=s[temp];
					s[temp]=s[i];
					s[i]=pp;
				}
			}
			if(flag==0) break;
		}
		if(flag) printf("%d\n",ans);
		else printf("-1\n");

	}
	return 0;
}