#include <bits/stdc++.h>
using namespace std;
int N,S,M;

vector<int> applicants[103];
vector<char> x;
map< vector<char>,int > dp;
int cost[103];

void initail()
{
	stringstream now;
	string temp;
	getline(cin,temp);
	x.clear();
	int sum=0,k;
	for(int i=0;i<S;i++)
		x.push_back(0);
	for(int i=0;i<M;i++)
	{
		getline(cin,temp);
		now.clear();
		now.str(temp);
		now>>k;
		sum+=k;
		while(now>>k)
			if(x[k-1]<2) x[k-1]++;
	}
	dp.clear();
	dp[x]=sum;
	for(int i=0;i<N;i++)
	{
		getline(cin,temp);
		now.clear();
		now.str(temp);
		now>>cost[i];
		applicants[i].clear();
		while(now>>k)
			applicants[i].push_back(k-1);
	}
}

void core_dp()
{
	map< vector<char>,int >::iterator it;
	vector<char> temp;
	int len,costnow;
	for(int i=0;i<N;i++)
	{
		it=dp.end();
		do
		{	
			it--;
			temp=it->first;
			costnow=it->second;
			len=applicants[i].size();
			for(int j=0;j<len;j++)
				if(temp[applicants[i][j]]<2)
					temp[applicants[i][j]]++;
			costnow+=cost[i];
			if(dp.count(temp)==0||costnow<dp[temp])
				dp[temp]=costnow;
		}while(it!=dp.begin());
	}
	it=dp.end();
	it--;
	printf("%d\n",it->second);
}

int main()
{
	while(scanf("%d%d%d",&S,&M,&N)==3)
	{
		if(S==N&&S==M&&S==0) break;
		initail();
		core_dp();
	}
	return 0;
}