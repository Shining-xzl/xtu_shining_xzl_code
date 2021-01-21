#include <cstdio>
#include <cstring>
using namespace std;
const int K[]={6,2,5,5,4,5,6,3,7,6};
int n,m;
int dp[56][3004],ans,num;
int mod[10][54];

void get_mod()
{
	for(int i=0;i<10;i++)
		mod[i][0]=i%m;
	for(int i=1;i<=50;i++)
		for(int j=0;j<10;j++)
			mod[j][i]=mod[j][i-1]*10%m;
}

int Min(int a,int b) { return a<b?a:b; }

void core_dp()
{	
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0]=0;
	int premod;
	for(int i=1;i<=(n>>1);i++)//i位数
	{	
		for(int k=0;k<m;k++)//模数
		{
			for(int j=9;j>=0;j--)//最高位 
			{
				premod=k-mod[j][i-1];
				if(premod<0) premod+=m;
				dp[i][k]=Min(dp[i][k],dp[i-1][premod]+K[j]);//只取最小值，方便解码
				
			}
		}
	}
}

void print()
{
	bool flag=0,p=0;
	int i,k=0,temp;
	for(i=(n>>1);i>0;i--)
	{
		if(dp[i][0]<=n) break;
	}
	while(i>0&&dp[i][k]<=n)
	{
		flag=1;
		if(i==1) p=1;
		for(int j=9;j>=0;j--)
		{
			temp=k-mod[j][i-1];
			if(temp<0) temp+=m;
			if(dp[i-1][temp]+K[j]<=n)//注意，此处并不是dp[i][j],所以dp[i][j]只是理论最小火柴数
			{
				if(j!=0) p=1;
				if(p) printf("%d",j),n-=K[j];//去除前导0，非前导0才减去火柴
				k=temp;
				break;
			}
		}
		i--;
	}
	if(!flag) printf("-1");
	printf("\n");
}

int main()
{
	int con=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		get_mod();
		core_dp();+
		printf("Case %d: ",++con);
		print();
	}	
	return 0;
}
