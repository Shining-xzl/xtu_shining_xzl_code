#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int n;
string f[34];
int dp[1<<16][36];
int some[36][36];

bool check(string &a,string &b)
{
	int lena=a.length();
	int lenb=b.length();
	if(lena<lenb) return 0;
	for(int i=0;i+lenb<=lena;i++)
	{
		int op;
		for(op=0;op<lenb;op++)
			if(b[op]!=a[op+i])
			{
				break;
			}
		if(op==lenb) return 1;
	}
	return 0;
}

bool cmp(const string &a,const string &b)
{
	return a.length()>b.length();
}

void process()
{
	bool k[17]={0};
	string temp;
	sort(f,f+n,cmp);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(k[j]) continue;
			temp=f[j];
			reverse(temp.begin(),temp.end());
			if(check(f[i],f[j])||check(f[i],temp))
				k[j]=1;
		}
	int op=0;
	for(int i=0;i<n;i++)
		if(!k[i])
			f[op++]=f[i];
	for(int i=0;i<op;i++)
	{
		f[i+op]=f[i];
		reverse(f[i+op].begin(),f[i+op].end());
	}
	n=op;
}

void get_some()
{
	memset(some,0,sizeof(some));
	for(int i=0;i<n*2;i++)
		for(int j=0;j<n*2;j++)
		{
			int lena=f[i].length();
			for(int start=(i==j?1:0);start<lena;start++)
			{
				int op;
				for(op=0;op+start<lena;op++)
					if(f[j][op]!=f[i][op+start])
						break;
				if(op+start==lena)
				{
					some[i][j]=lena-start;
					break;
				}
			}
		}
}

void get_dp()
{
	int ans=INF;
	memset(dp,INF,sizeof(dp));
	dp[1][0]=f[0].length();
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<n;j++)
		{
			int len=f[j].length();
			for(int k=0;k<n;k++)
			{
				if(j==k) continue;
				if(!((i&(1<<j))&&(i&(1<<k)))) continue;
				if(dp[i-(1<<j)][k]<INF)
				{
					dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+len-some[k][j]);
					dp[i][j+n]=min(dp[i][j+n],dp[i-(1<<j)][k]+len-some[k][j+n]);
				}
				if(dp[i-(1<<j)][k+n]<INF)
				{
					dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k+n]+len-some[k+n][j]);
					dp[i][j+n]=min(dp[i][j+n],dp[i-(1<<j)][k+n]+len-some[k+n][j+n]);
				}
			}
		}
	}
	if(n==1) ans=f[0].length()-some[0][0];
	else
	{
		for(int i=0;i<n*2;i++)
			ans=min(ans,dp[(1<<n)-1][i]-some[i][0]);
	}
	if(ans==1) ans=2;
	printf("%d\n",ans);
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
			cin>>f[i];
		process();
		get_some();
		get_dp();
	}
	return 0;
} 
