#include <cstdio>

using namespace std;
int n;
int sum[3004],x;

int get(int k)
{
	int st=sum[k],temp=st,con=1;
	for(int i=k+1;i<=n;i++)
	{
		temp=sum[i]-sum[k];
		if(temp==st)
		{
			con++;
			k=i;
		}
	}
	if(temp==st) return con;
	else return -99999;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int time,ans,temp;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum[i]=sum[i-1]+x;
			// printf("%d ",sum[i]);
		}
		// printf("\n");
		// continue;
		ans=n-1;
		for(int i=1;i<=n;i++)
		{
			temp=get(i);
			temp=n-temp;
			ans=(ans>temp?temp:ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}