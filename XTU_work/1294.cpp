#include <cstdio>
#include <cstring>
using namespace std;

int sum[10002];
char s[10002];

void build()
{
	int len=strlen(s);
	for(int i=1;i<len;i++)
	{
		sum[i]=sum[i-1];
		if(s[i]!=s[i-1])
			sum[i]++;
	}
	return;
}

int main()
{
	int time,n,a,b,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		build();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&a,&b);
			a--;
			b--;
			ans=sum[b]-sum[a];
			printf("%d\n",ans);
		}
	}
	return 0;
}
