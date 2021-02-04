/*
计算几何加dp
环状的。。。麻烦死了 
dp[strat][len]代表从start点出发连续len条边均可覆盖的最小代价 
状态转移。。。。看着办吧
辅助参量 s[i],l[i]代表第i个光源，可照射从s[i]点出发,l[i]条边。

要计算第i个光源照射的边：
考虑一条边，端点(x1,y1),(x2,y2)，考虑内外关系，只要找到一个点在多边形内部，
如果边的方程ax+by+c=0;内点为(x0,y0),那么（x0*a+y0*b+c）*(ax+by+c)<0即可说明光源可照射此边
内点为多边形的坐标和的平均值 
 
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;

int n,m;
struct point
{
	float x,y;
}v[32],light[1003];
int c[1003];
float midx,midy;
int dp[32][32];
int s[1003],l[1003];

bool check(float x1,float y1,float x2,float y2,float x,float y)//判断是否存在直线两边
{
	float a,b,c;
	a=y1-y2;
	b=x2-x1;
	c=x1*y2-x2*y1;
	if((x*a+y*b+c)*(midx*a+midy*b+c)<0) return 1;//数学知识 
	else return 0;
}

void process()
{
	int pre,now;
	bool flag;
	for(int i=0;i<m;i++)
	{
		pre=0;
		flag=0;
		l[i]=0;
		for(int j=n-1;j>=0;j--)//反向，方便环的处理 
		{
			now=j;
			if(check(v[pre].x,v[pre].y,v[now].x,v[now].y,light[i].x,light[i].y))
			{
				if(!flag) s[i]=now;//不断更新起点 
				l[i]++;
			}
			else if(l[i]>0) flag=1;//不连续即断开 
			pre=now;
		}
	}
	
}

int Min(int a,int b)
{
	return a<b?a:b;
}

int addx_len(int i,int start,int len)//判断是否可结合，仔细思考，环状处理模板 
{
	int end=start+len;
	int xs=s[i],xe=s[i]+l[i];
	if(xe<n)//关键点，画图可知 
		end%=n;
	if(end>=xs&&end<=xe)//可结合 
	{
		return xe-end+len;
	}
	else return len;
}

void core_dp()
{
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<n;i++)//初始化 
		dp[i][0]=0;
	for(int len=0;len<n;len++)//长度 
		for(int start=0;start<n;start++)//起点 
		{	
			if(dp[start][len]==INF) continue;
			for(int i=0;i<m;i++)//光源放在第三层，方便状态的连续性，同样的光源购买第二次无用，所以不同于背包问题 
			{
				int lenx=addx_len(i,start,len);
				dp[start][lenx]=Min(dp[start][lenx],dp[start][len]+c[i]);
			}
		}
	int MIN=1e9;
	for(int i=0;i<n;i++)
		MIN=Min(MIN,dp[i][n]);
	
	if(MIN==1e9)
		printf("Impossible.\n");
	else printf("%d\n",MIN);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	midx=0,midy=0;
	while(scanf("%d",&n)&&n)
	{
		midx=midy=0;
		for(int i=0;i<n;i++)
			scanf("%f%f",&v[i].x,&v[i].y),midx+=v[i].x,midy+=v[i].y;
		midx/=n;
		midy/=n;//内点 
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%f%f%d",&light[i].x,&light[i].y,&c[i]);
		process();//加工辅助参量 
		core_dp();
	}
	return 0;
} 
