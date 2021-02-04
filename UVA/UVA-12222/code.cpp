#include <cstdio>
#include <cstring>
using namespace std;

struct car
{
	int time;
	int v;
}a[203],b[203];
int n,lena,lenb;

void initail()
{
	char s[3];
	scanf("%d",&n);
	lena=lenb=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='A')
		{
			lena++;
			scanf("%d%d",&a[lena].time,&a[lena].v);
		}
		else
		{
			lenb++;
			scanf("%d%d",&b[lenb].time,&b[lenb].v);
		}
	}
}

inline int Min(int a,int b)
{
	return a<b?a:b;
}

int dp[203][203][2];

void core_dp()
{
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0][1]=0;
	dp[0][0][0]=0;
	int time,end;
	for(int i=0;i<=lena;i++)
		for(int j=0;j<=lenb;j++)
		{
			time=dp[i][j][1];
			end=0;
			for(int k=i+1;k<=lena;k++)
			{
				if(time<a[k].time) time=a[k].time;
				if(end<a[k].v+time) end=a[k].v+time;
				dp[k][j][0]=Min(dp[k][j][0],end);
				time+=10;
				end+=10;
			}
			time=dp[i][j][0];
			end=0;
			for(int k=j+1;k<=lenb;k++)
			{
				if(time<b[k].time) time=b[k].time;
				if(end<b[k].v+time) end=b[k].v+time;
				dp[i][k][1]=Min(dp[i][k][1],end);
				time+=10;
				end+=10;
			}
		}
	printf("%d\n",Min(dp[lena][lenb][0],dp[lena][lenb][1]));
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
