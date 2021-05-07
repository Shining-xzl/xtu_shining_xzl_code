#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1e9+7; 
int n,k;
bool is_palindromic[13][1<<11];
int dp[403][1<<13];

void dfs(int n,int x)
{
	is_palindromic[n][x]=1;
	if(n+2>11) return;//n最大是10 
	dfs(n+2,(x<<1)+1+(1<<n+1));
	dfs(n+2,x<<1);
}

void prime_process()//dfs构造 
{
	dfs(1,1);
	dfs(1,0);
	dfs(2,3);
	dfs(2,0);
}

/*
dp[n][s]表示，第n位，前k个串的状态为s时的可用个数 
状态转移时，在s的末位加0(1)即可，判断是否回文，转移到dp[n+1][s'] 
PS：当存在k位的回文时，一定存在k-1(k-2)的子回文，即一定会先判断子回文，
因此不存在 k-1(k-2)的回文时，一定不存在大于k的回文。（反证） 
*/
int solve()//状压DP 
{
	if(n<k) return 1<<n;//特殊情况 
	memset(dp,0,sizeof(dp));
	int temp1;
	for(int i=0;i<(1<<k);i++)
		if(!is_palindromic[k][i]) dp[k][i]=1;//初值，开始处理长度为k，其他由此串转移 
	for(int i=k;i<n;i++)
		for(int j=0;j<(1<<k);j++)
		{
			if(dp[i][j]==0) continue;
			temp1=j+(1<<k);//temp1为末为加1，j为加0
			/*
				决策方法：
				后k+1位不回文，且后k位不回文 
			*/ 
			if((!is_palindromic[k+1][temp1])&&(!is_palindromic[k][temp1>>1])) dp[i+1][temp1>>1]=(dp[i+1][temp1>>1]+dp[i][j])%MOD;
			if((!is_palindromic[k+1][j])&&(!is_palindromic[k][j>>1])) dp[i+1][j>>1]=(dp[i+1][j>>1]+dp[i][j])%MOD;
		}
	int ans=0;
	for(int i=0;i<(1<<k);i++)
		ans=(ans+dp[n][i])%MOD;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	prime_process();//预处理回文(palindromic)串 
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&k);
		printf("%d\n",solve());
	} 
	return 0;
} 
