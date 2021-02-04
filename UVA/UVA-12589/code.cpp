#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=-0x3f3f3f3f;
int n,k;
struct vector
{
	int x,y;
	bool operator < (const vector &a) const
	{
		return x*a.y<y*a.x;
	}	
}library[56];

int dp[53][2504];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time,LIM,lim,temp,Case=0;
	scanf("%d",&time);
	while(time--)
	{
		LIM=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&library[i].x,&library[i].y);
			if(library[i].y>LIM) LIM=library[i].y;
		}
		sort(library+1,library+n+1);
		memset(dp,INF,sizeof(dp));
		dp[0][0]=0;
		LIM*=n;
		for(int i=1;i<=n;i++)
		{
			lim=i;
			if(lim>k) lim=k;
			for(int num=k-1;num>=0;num--)
			{
				for(int h=0;h<LIM;h++)
				{
					if(dp[num][h]>=0)
					{
						temp=dp[num][h];
						temp+=(2*h+library[i].y)*library[i].x;
						if(temp>dp[num+1][h+library[i].y]) dp[num+1][h+library[i].y]=temp;
					}
				}
			}
		}
		int ans=INF;
		for(int i=1;i<=LIM;i++)
		{
			if(dp[k][i]>ans) ans=dp[k][i];
		}
		printf("Case %d: %d\n",++Case,ans);
	}
	return 0;
} 
