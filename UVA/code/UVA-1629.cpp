#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,k;
int sum[23][23];
int dp[23][23][23][23];

int num_of_cherry(int x1,int y1,int x2,int y2)//该小矩阵内的cherry数量 
{
	return sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1];
}

int dp_process_core(int x1,int y1,int x2,int y2)
{
	int &ans=dp[x1][y1][x2][y2];
	if(x1>x2||y1>y2) return ans=0;//越界返回0 
	if(ans<INF) return ans;//有记录 直接返回 
	if(num_of_cherry(x1,y1,x2,y2)==1) return ans=0;
	if(num_of_cherry(x1,y1,x2,y2)==0) return INF;//无效，直接返回最大值 
	int l=y2-y1+1,c=x2-x1+1;
	int temp;
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			if(i==x2&&j==y2) continue;//无效 
			temp=dp_process_core(x1,y1,i,j);//四个矩阵 
			temp+=dp_process_core(x1,j+1,i,y2);
			temp+=dp_process_core(i+1,y1,x2,j);
			temp+=dp_process_core(i+1,j+1,x2,y2);
			if(i!=x2) temp+=l;//横向切一刀 
			if(j!=y2) temp+=c;//纵向切一刀 
			if(temp<0||temp>=INF) temp=INF;//temp值越界 ，无效值 
			if(temp<ans) ans=temp; 
		}
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int x,y,ans,Case=0;
	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		memset(sum,0,sizeof(sum));
		memset(dp,INF,sizeof(dp));
		while(k--)
		{
			scanf("%d%d",&x,&y);
			sum[x][y]=1; 
		}
		for(int i=1;i<=n;i++)//矩阵前缀和（0，0）到（x，y）的矩阵和 
		{
			for(int j=1;j<=m;j++)
				sum[i][j]+=sum[i][j-1];
			for(int j=1;j<=m;j++)
				sum[i][j]+=sum[i-1][j];
		}
		ans=dp_process_core(1,1,n,m);
		printf("Case %d: %d\n",++Case,ans);
	}	
	return 0;
} 
