#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

char s[102];
int dp[102][102],len,cirlce[102][102];
string ans[102][102];

void process_pre()
{
	int op,next;
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			cirlce[i][j]=1;
			op=i;
			next=j+1;
			while(s[op]==s[next])
			{
				if(op==j) cirlce[i][j]++;
				op++;
				next++;
				if(op>j) op=i;
			}	
		}
	}
}

void AtoB(string &a,int l,int r)
{
	a="";
	for(int i=l;i<=r;i++)
		a+=s[i];
}

string turn(int a)
{
	string x="";
	while(a>0)
	{
		x+=char(a%10+'0');
		a/=10;
	}
	reverse(x.begin(),x.end());
	return x;
}

int process_core(int l,int r)
{
	int &now=dp[l][r];
	string &xans=ans[l][r],temp;
	if(now<INF) return now;
	now=r-l+1;
	int len=now;
	AtoB(xans,l,r);
	for(int i=l;i<r;i++)
	{
		int ll=i-l+1;
		int num=cirlce[l][i];
		if(len%ll==0&&len/ll<=num)
		{
			int f=len/ll;
			process_core(l,i);
			temp=turn(f)+'('+ans[l][i]+')';
			if(temp.length()<now)
			{
				now=temp.length();
				xans=temp;
			}
		}
	}
	for(int i=l;i<r;i++)
	{
		process_core(l,i);
		process_core(i+1,r);
		if(now>dp[l][i]+dp[i+1][r])
		{
			now=dp[l][i]+dp[i+1][r];
			xans=ans[l][i]+ans[i+1][r]; 
		}
	}
	return now;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",&s)==1)
	{
		memset(dp,INF,sizeof(dp));
		len=strlen(s);
		process_pre();
		process_core(0,len-1);
		cout<<ans[0][len-1]<<endl;
	}
	return 0;
} 
