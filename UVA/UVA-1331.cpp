#include <cstdio>
using namespace std;
const double inf=1e+18;
int x[53],y[53];
int n;
double dp[53][53];

inline double area(int a,int b,int c)
{
	double x1,x2,y1,y2,ans;
	x1=(double)x[a]-x[b];
	x2=(double)x[a]-x[c];
	y1=(double)y[a]-y[b];
	y2=(double)y[a]-y[c];
	ans=(x1*y2-x2*y1)/2.0;
	if(ans<0) ans=-ans;
	return ans;
}

void initail()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=inf;
	for(int i=0;i<n;i++)
		dp[i][i+1]=0.0;
}

double Max(double a,double b)
{
	return a>b?a:b;
}
double Min(double a,double b)
{
	return a<b?a:b;
}
double Fabs(double a)
{
	return a<0?-a:a;
}

bool check(int a,int b,int c)
{
	double areax=area(a,b,c),temp;
	for(int i=0;i<n;i++)
	{
		if(i==a||i==b||i==c) continue;
		temp=area(a,i,b)+area(a,i,c)+area(b,i,c);
		if(Fabs(temp-areax)<1e-5) return 1;
	}
	return 0;
}

void core_dp()
{
	double temp;
	for(int len=2;len<n;len++)
	{
		for(int s=0;s+len<n;s++)
		{
			int e=s+len;
			for(int j=s+1;j<e;j++)
			{
				if(check(s,j,e)) continue;
				temp=area(s,j,e);
				temp=Max(temp,dp[s][j]);
				temp=Max(temp,dp[j][e]);
				dp[s][e]=Min(dp[s][e],temp);
			}
		}
	}
	printf("%.1lf\n",dp[0][n-1]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		core_dp();
	}
	return 0;
}