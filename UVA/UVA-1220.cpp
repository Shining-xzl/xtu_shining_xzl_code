#include <bits/stdc++.h>
using namespace std;
map<string,int> name;
vector<int> son[203];
int n,id;
int dp[203][2];
bool f[203][2];

void dfs(int now)
{	
	dp[now][0]=0;
	dp[now][1]=1;
	if(son[now].empty()) return;	
	int len=son[now].size(),temp;
	bool tempf;
	for(int i=0;i<len;i++)
	{
		dfs(son[now][i]);
		dp[now][1]+=dp[son[now][i]][0];
		if(f[son[now][i]][0]) f[now][0]=1;
		temp=dp[son[now][i]][0];
		tempf=f[son[now][i]][0];
		if(temp<dp[son[now][i]][1])
		{
			temp=dp[son[now][i]][1];
			tempf=f[son[now][i]][1];
		}
		if(dp[son[now][i]][0]==dp[son[now][i]][1])
			tempf=1;
		dp[now][0]+=temp;
		if(tempf) dp[now][0]=tempf;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	string a,b;
	int temp;
	bool tempf;
	while(scanf("%d",&n)==1&&n)
	{
		name.clear();
		cin>>a;
		id=0;
		name[a]=id++;
		for(int i=0;i<n;i++)
			son[i].clear();
		memset(f,0,sizeof(f));
		for(int i=1;i<n;i++)
		{
			cin>>a>>b;
			if(name.count(a)==0)
				name[a]=id++;
			if(name.count(b)==0)
				name[b]=id++;
			son[name[b]].push_back(name[a]);
		}
		dfs(0);
		temp=dp[0][1];
		tempf=f[0][1];
		if(temp<dp[0][0])
		{
			temp=dp[0][0];
			tempf=f[0][0];
		}
		if(dp[0][0]==dp[0][1])
			tempf=1;
		printf("%d %s\n",temp,tempf?"No":"Yes");
	}
	return 0;
}