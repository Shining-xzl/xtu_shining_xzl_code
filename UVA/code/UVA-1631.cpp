#include <cstdio>
#include <cstring>
using namespace std;
char s[1003],t[1003];
int len;
int dp[1003][10][10][10];

int Min(int a,int b)
{
	return a<b?a:b; 
}

int core_dp(int pos,int a,int b,int c)//记忆化搜索 
{
	//pos当前位置，a，b，c代表pos，pos+1，pos+2位置旋钮状态
	//直接将a转到最终态，枚举同时旋转2个、3个的次数
	//有向上向下两种方式 
	int &ans=dp[pos][a][b][c];
	if(ans!=-1) return ans;
	if(pos>=len) return 0;
	int up_step=(t[pos]-a+10)%10;
	int down_step=10-up_step;
	ans=1e9;
	for(int i=0;i<=up_step;i++)
		for(int j=0;j<=i;j++)
			ans=Min(ans,core_dp(pos+1,(b+i)%10,(c+j)%10,s[pos+3])+up_step);
	for(int i=0;i<=down_step;i++)
		for(int j=0;j<=i;j++)
			ans=Min(ans,core_dp(pos+1,(b-i+10)%10,(c-j+10)%10,s[pos+3])+down_step);
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%s%s",s,t)==2)
	{
		memset(dp,-1,sizeof(dp));
		len=strlen(s);
		for(int i=0;i<len;i++)
			s[i]-=48,t[i]-=48;
		for(int i=0;i<=3;i++)
			s[len+i]=t[len+i]=0;//加三位，方便dfs判断边界 
		printf("%d\n",core_dp(0,s[0],s[1],s[2]));
	} 
	return 0;
} 
