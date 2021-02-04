#include <cstdio>
#include <cstring>
using namespace std;
int sum[40003];
int n,m,d;

void initail()
{
	scanf("%d%d%d",&n,&m,&d);
	int w;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		sum[i]=sum[i-1]+w; 
	}
}

int dp[40004][2];

int Min(int a,int b)
{
	return a<b?a:b;
} 

bool check_dp(int stand)
{
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=2;i<=n;i+=2)
	{
		for(int len=1;len*2<=i&&len<=d;len++)
		{
			if(sum[i]-sum[i-len]>stand) break;
			if(sum[i-len]-sum[i-len*2]>stand) continue;
			dp[i][0]=Min(dp[i][0],dp[i-len*2][1]+1);
			dp[i][1]=Min(dp[i][1],dp[i-len*2][0]+1);
		}
	}
	return dp[n][(m-1)&1]<=m-1;
} 

void binary_search()
{
	if((n&1)||(n<(m-1)*2)||(n>(m-1)*2*d))
	{
		printf("BAD\n");
		return;
	}
	int l=1,r=sum[n],ans,mid;
	ans=r;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check_dp(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		binary_search();
	}
	return 0;
} 
