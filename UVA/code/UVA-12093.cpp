/*
�ѵ�����״̬��ʾ
dp[][0] ����ȫ���ǣ���������(����)0�� 
dp[][1] ����ȫ���ǣ���������(����)1�� 
dp[][2] ����ȫ���ǣ���������(����)2�㣬����װBװ�� 
dp[][3] ���ӽڵ�����ȫ���ǣ�����ӽڵ�����жϵ� 
 
dp[x][0]=Min(dp[v][1],dp[v][2])
dp[x][1]=Min(dp[v][0],dp[v][1],dp[v][2])+C1,�����,������ӽڵ�����Bװ�ã����ɲ���C1
dp[x][2]=Min(dp[v][0],dp[v][1],dp[v][2],dp[v][3])+C2
dp[x][3]=Min(dp[v][0],dp[v][1],dp[v][2])

answer=Min(dp[x][0],dp[x][1],dp[x][2]);

*/
#include <cstdio>
#include <vector> 
using namespace std;
int n,c1,c2;
int dp[10003][4];
vector< vector<int> > son;

int Min(int a,int b)
{
	return a<b?a:b;
}

void dfs_core_dp(int x,int fa)
{
	dp[x][0]=0;
	dp[x][1]=c1;
	dp[x][2]=c2;
	dp[x][3]=0;
	int len=son[x].size(),v,min_of_cost,sum=0,diff=1e9;
	for(int i=0;i<len;i++)
	{
		v=son[x][i];
		if(v==fa) continue;
		dfs_core_dp(v,x);
		min_of_cost=Min(Min(dp[v][0],dp[v][1]),dp[v][2]);
		dp[x][0]+=dp[v][1];
		dp[x][1]+=min_of_cost;
		dp[x][2]+=Min(min_of_cost,dp[v][3]);
		dp[x][3]+=min_of_cost;
		sum+=min_of_cost;
		diff=Min(diff,dp[v][2]-min_of_cost); 
	}
	sum+=diff;
	if(sum<dp[x][1]) dp[x][1]=sum;
} 

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,v;
	while(scanf("%d%d%d",&n,&c1,&c2)==3)
	{
		if(n==0&&c1==0&&c2==0) break;
		son.clear();
		son.resize(n+1);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&v);
			son[x].push_back(v);
			son[v].push_back(x);
		}
		dfs_core_dp(1,0);
		printf("%d\n",Min(Min(dp[1][0],dp[1][1]),dp[1][2]));
	}
	return 0;
} 
