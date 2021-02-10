#include <cstdio>
#include <cstring> 
using namespace std;
const int inf=-0x3f3f3f3f;
int n,op;
int location[104],c[104];
int dp[104][104][104][2];

void initail()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&location[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	op=n;
	while(location[op]>0)
	{
		location[op+1]=location[op];
		c[op+1]=c[op];
		op--;
	}
	n++;
	op++;
	location[op]=0;
	c[op]=0;

}

int Max(int a,int b)
{
	return a>b?a:b;
} 

void dfs(int start,int end,int num)//走完了start到end，还有num个需要送 
{
	int &ans1=dp[start][end][num][1];
	int &ans0=dp[start][end][num][0];
	if(ans1>-1e9||ans0>-1e9) return;
	else if(n-end+start-1<num||start>=end)
	{	
		ans1=ans0=-1e9+1;
		return;
	}
	ans1=ans0=-1e9+1;
	dfs(start+1,end,num+1);
	dfs(start+1,end,num);
	dfs(start,end-1,num+1);
	dfs(start,end-1,num);
	//0，1 分别代表当前位置的最左最右，状态转移显然 
	ans0=Max(ans0,dp[start+1][end][num][0]-(location[start+1]-location[start])*num);
	ans0=Max(ans0,dp[start+1][end][num][1]-(location[end]-location[start])*num);
	ans0=Max(ans0,dp[start+1][end][num+1][0]-(location[start+1]-location[start])*(num+1)+c[start]);
	ans0=Max(ans0,dp[start+1][end][num+1][1]-(location[end]-location[start])*(num+1)+c[start]);

	ans1=Max(ans1,dp[start][end-1][num][0]-(location[end]-location[start])*num);
	ans1=Max(ans1,dp[start][end-1][num][1]-(location[end]-location[end-1])*num);
	ans1=Max(ans1,dp[start][end-1][num+1][0]-(location[end]-location[start])*(num+1)+c[end]);
	ans1=Max(ans1,dp[start][end-1][num+1][1]-(location[end]-location[end-1])*(num+1)+c[end]);
	return;
}

void core_dp()
{
	memset(dp,inf,sizeof(dp)); 
	for(int i=0;i<n;i++)
		dp[op][op][i][0]=dp[op][op][i][1]=0;
	dfs(1,n,0);
	printf("%d\n",Max(dp[1][n][0][0],dp[1][n][0][1]));
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
		core_dp();
	}
	return 0;
} 
