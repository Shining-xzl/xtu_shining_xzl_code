#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL k,dp[67][67];
int n,d;
int pos1[67],pos0[67],len1,len0;

void initial()
{
	len1=len0=0;
	for(int i=1;i<=n;i++)
	{
		if(k&(1ULL<<n-i)) pos1[++len1]=i;
		else pos0[++len0]=i;
	}
}

inline bool right(int i,int j,int now)
{
	if(now==1)
	{
		if(j==len1) return 0;
		if(i==len0) return 1;
		else return pos0[i+1]+d>=pos1[j+1];
	}
	else
	{
		if(i==len0) return 0;
		if(j==len1) return 1;
		else return pos1[j+1]+d>=pos0[i+1];
	}
} 
int Case=0;
void core_dp()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1ULL;
	for(int i=0;i<=len0;i++)
		for(int j=0;j<=len1;j++)
		{
			if(right(i,j,0))
				dp[i+1][j]+=dp[i][j];
			if(right(i,j,1))
				dp[i][j+1]+=dp[i][j];
		}
	printf("Case %d: ",++Case);
	cout<<dp[len0][len1];
}

ULL get_ans(bool k)
{
	ULL ans=0ULL;
	int pos0=0,pos1=0;
	for(int i=0;i<n;i++)
	{
		if(k)
		{
			if(right(pos0,pos1,1))
			{
				ans=ans*2+1ULL;
				pos1++;
			}
			else
			{
				ans*=2;
				pos0++;
			}
		}
		else
		{
			if(right(pos0,pos1,0))
			{
				ans*=2;
				pos0++;
			}
			else
			{
				ans=ans*2+1ULL;
				pos1++;
			}
		}
	}
	return ans;
}

int main()
{
	while(cin>>n>>d>>k)
	{
		initial();
		core_dp();
		cout<<' '<<get_ans(0)<<' '<<get_ans(1)<<endl;
	}
	return 0;
} 
