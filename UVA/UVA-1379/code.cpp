#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,g,ans;
int dp[2][6][6][6][6];

struct win
{
	int val,id;
    win(int a=0,int b=0):val(a),id(b) {} 
	bool operator < (const win &a) const 
	{
		return val>a.val;
	}
	
}s[105][203];


void initail()
{
	scanf("%d%d%d",&n,&m,&g);
	g+=10;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&s[i][j].val);
			s[i][j].id=j; 
		}
		sort(s[i]+1,s[i]+n+1);
//		for(int j=1;j<=n;j++)
//			printf("%d ",s[i][j].val);
//		printf("\n");
	}
}

int Max(int a,int b)
{
	return a>b?a:b;
}

int get_id(int p,int num)
{
	if(p==0||num==0) return 0;
	else return s[p][num].id; 
}

void core_dp()
{
	ans=0;
	memset(dp[0],0,sizeof(dp[0]));
	int now,pre=0,x[230]={0};
	for(int i=1;i<=g;i++)
	{
		scanf("%d",&x[i]);
		now=!pre;
		memset(dp[now],0,sizeof(dp[now]));
		if(x[i])
		{
			for(int k=1;k<=5;k++)
			{
				for(int a=0;a<=5;a++)
				{
					if(i>1&&get_id(x[i],k)==get_id(x[i-1],a)) continue;
					for(int b=0;b<=5;b++)
					{
						if(i>2&&get_id(x[i],k)==get_id(x[i-2],b)) continue;
						for(int c=0;c<=5;c++)
						{
							if(i>3&&get_id(x[i],k)==get_id(x[i-3],c)) continue;
							for(int d=0;d<=5;d++)
							{
								if(i>4&&get_id(x[i],k)==get_id(x[i-4],d)) continue;
								if(dp[now][k][a][b][c]<dp[pre][a][b][c][d]+s[x[i]][k].val)
									dp[now][k][a][b][c]=dp[pre][a][b][c][d]+s[x[i]][k].val;
								ans=Max(dp[now][k][a][b][c],ans);
							}
						}
					}
				}
			}
		}
		else
		{
			for(int a=0;a<=5;a++)
				for(int b=0;b<=5;b++)
					for(int c=0;c<=5;c++)
						for(int d=0;d<=5;d++)
							dp[now][0][a][b][c]=Max(dp[now][0][a][b][c],dp[pre][a][b][c][d]);
		} 
		pre=now;
	}
	printf("%d.%02d\n",ans/100,ans%100);
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		core_dp();
	}
	return 0;
} 
