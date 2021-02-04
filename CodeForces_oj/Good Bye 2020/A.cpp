#include <cstdio>
#include <cstring>
using namespace std;
int n;
int s[54];
bool a[54];
int main()
{
//	freopen("in.txt","r",stdin);
	int time,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		memset(a,0,sizeof(a));
		ans=0;
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				if(a[s[i]-s[j]]==0)
				{
					ans++;
					a[s[i]-s[j]]=1;	
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}