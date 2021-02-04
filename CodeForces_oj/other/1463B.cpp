#include <cstdio>
#include <algorithm>
using namespace std;
int s[56];
int n;
long long sum,now1,now2;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]),sum+=s[i];
		now1=now2=0;
		for(int i=1;i<=n;i++)
		{
			if(i&1) now1+=s[i]-1;
			else now2+=s[i]-1;
		}
		if((now1<<1)<=sum)
		{
			for(int i=1;i<=n;i++)
				if(i&1) printf("1 ");
				else printf("%d ",s[i]);
		}
		else if((now2<<1)<=sum)
		{
			for(int i=1;i<=n;i++)
				if(!(i&1)) printf("1 ");
				else printf("%d ",s[i]);
		}
		printf("\n");
	}
	return 0;
}