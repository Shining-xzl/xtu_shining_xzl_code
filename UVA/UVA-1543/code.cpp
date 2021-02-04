#include <cstdio>
#include <cmath>
#include <cstring> 
using namespace std;
const double pi=3.14159265358979323846;
int n,m;
double point[43];
double plen[43][43];
double dp[43][43][43];

void process()
{
	double angle;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			angle=(point[j]-point[i])*pi*2.0;
			if(angle>pi) angle=2.0*pi-angle;
			plen[i][j]=sin(angle/2.0)*2;
		}
	}
}

double area(double &a,double &b,double &c)
{
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double Max(double a,double b)
{
	return a>b?a:b;
}

void core_dp()
{
	memset(dp,0,sizeof(dp));
	for(int i=2;i<m;i++)//i¸öµã 
	{
		for(int start=1;start<n;start++) 
		{
			for(int end=start+i-1;end<n;end++)
			{
				for(int k=end+1;k<=n;k++)
				{
					dp[i+1][start][k]=Max(dp[i+1][start][k],dp[i][start][end]+area(plen[start][end],plen[end][k],plen[start][k]));
				}
			}
		}
	}
	double ans=0;
	for(int start=1;start<n;start++)
		for(int end=start+1;end<=n;end++)
		{
			ans=Max(ans,dp[m][start][end]);
		}
	printf("%.6lf\n",ans);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		for(int i=1;i<=n;i++)
			scanf("%lf",&point[i]);
		process();
		core_dp();
	}
	return 0;
} 
