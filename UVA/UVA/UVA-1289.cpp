#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int map[10003],cnt;
set<int> all;
int n;
int dp[2503][52],c[2503];
long long p[2503];

int Min(int a,int b)
{
	return a<b?a:b;
}

/*
想象成每次从每个堆顶取碟子，每次只能取同一种类的（相同大小的看出一个），
先做一个整体排序，set储存整体，即每一种碟子最终的位置。
若同一种碟子在k堆中存在，则需要取k次，但如果上一种类的碟子与下一种类的碟子出现在同一堆，可衔接起来，即减少了一次
dp目的：尽可能增多衔接；
dp[n][k]，表示取到第n种，最后一次取第k堆时的状态
dp转移很明显，若n与n-1有共同的一堆，则可以进行转移 

辅助参量：p保存第i种碟子在那些堆中存在
怎么保存随便 
 
！！！！！！！！！
longlong 类型位运算要加1LL,不然会崩 
*/ 

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int x,m,pre,Case=0;
	while(scanf("%d",&n)==1)
	{
		all.clear();
		cnt=0;
		memset(map,0,sizeof(map));
		memset(dp,INF,sizeof(dp));
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			pre=-1;
			while(m--)
			{
				scanf("%d",&x);
				if(pre!=x)
				{
					if(map[x]==0) map[x]=(++cnt);
					p[map[x]]+=(1LL<<i);
					c[map[x]]++;
					all.insert(x);
				}
				pre=x;
			}
		}
		set<int>::iterator it;
		pre=0;
		int i=1,Min1=0,Min2;
		for(it=all.begin();it!=all.end();it++)
		{
			x=map[*it];
			Min2=INF;
			for(int j=0;j<n;j++)
			{
				if(((1ll<<j)&p[pre])&&((1ll<<j)&p[x]))//共同一堆，位运算保存有的堆，c保存数量 
				{
					for(int k=0;k<n;k++)
					{
						if(k==j&&c[x]!=1) continue;//如果只有一堆有，则可以直接转移 
						if((1ll<<k)&p[x])
						{
							dp[i][k]=Min(dp[i][k],dp[i-1][j]+c[x]-1);
							Min2=Min(Min2,dp[i][k]);
						}
					}
				}
			}
			for(int j=0;j<n;j++)
			{
				if((1ll<<j)&p[x])
				{
					dp[i][j]=Min(dp[i][j],Min1+c[x]);
					Min2=Min(Min2,dp[i][j]);
				}
			}
			Min1=Min2;
			pre=x;
			i++;
		}
		printf("Case %d: %d\n",++Case,Min1*2-n-1);
	}
	return 0;
} 
