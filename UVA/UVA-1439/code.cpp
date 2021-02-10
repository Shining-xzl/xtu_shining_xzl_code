#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int lim=(1<<15)+3;
int n,a[105],b[105];
bool p[17][17],diff[lim];
int all,dp[lim],bestson[lim];

void initail()
{
	all=0;
	memset(p,0,sizeof(p));
	memset(diff,0,sizeof(diff));
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		scanf(" %c %c ",&a[i],&b[i]);
		a[i]-='L';
		b[i]-='L';
		p[a[i]][b[i]]=p[b[i]][a[i]]=true;
		all|=(1<<a[i]);
		all|=(1<<b[i]);
	}
}

void process()
{
	for(int s=all;s>0;s=(s-1)&all)
	{
		diff[s]=true;
		for(int i=0;i<15;i++)
		{
			if(s&(1<<i))
			{
				for(int j=i+1;j<15;j++)
					if((s&(1<<j))&&p[i][j])
					{
						diff[s]=false;
						break;
					}	
			}
			if(!diff[s]) break;
		}
	}
}

int dfs_dp(int now)
{
	int &ans=dp[now],son;
	if(ans!=-1) return ans;
	if(now==0) return ans=0;
	ans=1e9;
	for(int s=now;s>0;s=(s-1)&now)
		if(diff[s])
		{
			son=now^s;
			if(dfs_dp(son)+1<ans)
			{
				ans=dp[son]+1;
				bestson[now]=s;
			}
		}
	return ans;
}

void print_each()
{
	int order=0,son,op[17];
	while(all>0)
	{
		son=bestson[all];
		for(int i=0;i<15;i++)
			if(son&(1<<i))
				op[i]=order;
		all^=son;
		order++;
	}
	for(int i=1;i<=n;i++)
	{
		if(op[a[i]]>op[b[i]]) swap(a[i],b[i]);
		printf("%c %c\n",a[i]+'L',b[i]+'L');
	}
}

int main()
{
	while(scanf("%d",&n)==1)
	{
		initail();
		process();
		printf("%d\n",dfs_dp(all)-2);
		print_each();
	}
	return 0;
} 
