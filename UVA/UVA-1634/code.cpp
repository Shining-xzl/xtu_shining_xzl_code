//¸´¿Ì°æ 
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct point
{
	int x,y;
	point(int x=0,int y=0):x(x),y(y) {}
	point operator - (const point &a) const
	{
		return point(x-a.x,y-a.y);
	}
}q[103],s[103];

int len;
point C;
int n,ans;
int dp[103][103];


int Max(int a,int b)
{
	return a>b?a:b;
}

int cross_product(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}

int distant(const point a)
{
	return a.x*a.x+a.y*a.y;
}

bool cmp(const point &a,const point &b)
{
	int t=cross_product(a-C,b-C);
	if(t!=0) return t>0;
	else return distant(a-C)<distant(b-C);
}

int abs(int a)
{
	return a>0?a:(-a);
} 

void core_dp()
{
	memset(dp,0,sizeof(dp));
	sort(q+1,q+len+1,cmp);
//	for(int i=1;i<=len;i++)
//	{
//		printf("%d %d\n",q[i].x-C.x,q[i].y-C.y);
//	}
//	printf("*****\n");
	int j,k,area;
	bool flag;
	for(int i=2;i<=len;i++)
	{
		j=i-1;
		while(j>0&&cross_product(q[i]-C,q[j]-C)==0) j--;
		flag=(j==i-1);
		while(j>0)
		{
			k=j-1;
			while(k>0&&cross_product(q[i]-q[k],q[j]-q[k])>0) k--;
			area=abs(cross_product(q[i]-C,q[j]-C));
			if(k>0) area+=dp[j][k];
			if(flag) dp[i][j]=area;
			ans=Max(ans,area);
			j=k;
		}
		if(flag)
		{
			for(j=2;j<=i;j++)
				dp[i][j]=Max(dp[i][j],dp[i][j-1]);
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&s[i].x,&s[i].y);
		ans=-1e9;
		for(int i=1;i<=n;i++)
		{
			C=s[i];
			len=0;
			for(int j=1;j<=n;j++)
				if((s[j].x>s[i].x&&s[j].y==s[i].y)||s[j].y>s[i].y)
					q[++len]=s[j];
			core_dp();
		}
		printf("%.1lf\n",ans*0.5);
	}
	return 0;
} 
