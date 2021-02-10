#include <cstdio>
#include <cstring>
using namespace std;

int dp[203][203][203];
int sample[203],n;
int pos[203];
void initail()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&sample[i]);		
	for(int i=1;i<=n;i++)
	{
		pos[i]=i;
		while(sample[i]==sample[pos[i]-1]) pos[i]--;
	}
}

int Max(int a,int b)
{
	return a>b?a:b;
}

int dfs_dp(int start,int end,int num)
{
	int &ans=dp[start][end][num],temp;
	if(ans!=0) return ans;
	if(pos[end]<=start) return ans=(end-start+1+num)*(end-start+1+num);
	if(start>end) return 0;
	ans=dfs_dp(start,pos[end]-1,0)+(num+end-pos[end]+1)*(num+end-pos[end]+1);
	for(int i=start;i<pos[end];i++)
	{
		if(sample[i]==sample[end]&&sample[i]!=sample[i+1])
		{
			temp=dfs_dp(start,i,num+end-pos[end]+1)+dfs_dp(i+1,pos[end]-1,0);
			ans=Max(ans,temp); 
		}
	}
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int time,Case=0;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		printf("Case %d: %d\n",++Case,dfs_dp(1,n,0));
	}
	return 0;
} 
