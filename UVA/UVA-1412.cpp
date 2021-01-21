#include <bits/stdc++.h>
using namespace std;
/*
map压缩id;
预处理状态转移的id号，减少map查找
id压缩dp转移；
仅转移手中的所有的钱（股票不用换算，因为大小关系不变）
*/
const int INF=12900;
double fund;
int m,n,k;
struct stock
{
	string name;
	int k;
	vector<double> price;
}all[10];

map< vector<int>,int > ID;
vector< vector<int> > rID;
double dp[103][INF];
int buy[INF][10],sell[INF][10];
int po[103][INF];
int op[103][INF];
int id;

void build_id_map()//构建状态与id的联系
{
	int sum;
	id=0;
	ID.clear();
	rID.clear();
	vector<int> sample(n+1,0),temp;
	queue< vector<int> > q;
	q.push(sample);
	rID.push_back(sample);
	ID[sample]=id++;
	while(!q.empty())
	{	
		temp=q.front();
		sample=temp;
		q.pop();
		sum=0;
		for(int i=0;i<n;i++)
			sum+=temp[i];
		if(sum==k) break;
		for(int i=0;i<n;i++)
		{
			sample[i]++;
			if(sample[i]<=all[i].k&&ID.count(sample)==0)
			{
				q.push(sample);
				rID.push_back(sample);
				ID[sample]=id++;
			}
			sample[i]--;
		}
	}
}

void print_path(int now,int j)
{
	if(now==0)
		return;
	print_path(now-1,po[now][j]);
	if(op[now][j]==0)
		printf("HOLD\n");
	else if(op[now][j]>0)
		cout<<"BUY "<<all[op[now][j]-1].name<<endl;
	else cout<<"SELL "<<all[-op[now][j]-1].name<<endl;
}

void update(double price,int i,int j,int f,int k)
{
	if(price>dp[i][j])
	{
		dp[i][j]=price;
		po[i][j]=f;
		op[i][j]=k;
	}
}

void core_dp()//id转移
{
	
	double use;
	for(int i=0;i<=m;i++)
		for(int j=0;j<id;j++)
			dp[i][j]=-1.0;
	dp[0][0]=fund;
	for(int i=0;i<m;i++)
		for(int j=0;j<id;j++)
			if(dp[i][j]>=0.0)
			{
				use=dp[i][j];
				update(use,i+1,j,j,0);
				for(int k=0;k<n;k++)
				{
					if(buy[j][k]!=-1&&use>=all[k].price[i])
					 	update(use-all[k].price[i],i+1,buy[j][k],j,k+1);
					if(sell[j][k]!=-1)
					 	update(use+all[k].price[i],i+1,sell[j][k],j,-k-1);
				}
			}
	printf("%.2lf\n",dp[m][0]);
	print_path(m,0);
}

void build_next()//构建转移id图，减少转移时的id查找
{
	vector<int> temp;
	for(int i=0;i<id;i++)
	{
		temp=rID[i];
		for(int j=0;j<n;j++)
		{
			temp[j]++;
			if(ID.count(temp))
				buy[i][j]=ID[temp];
			else buy[i][j]=-1;
			temp[j]--;
			temp[j]--;
			if(ID.count(temp))
				sell[i][j]=ID[temp];
			else sell[i][j]=-1;
			temp[j]++;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int s;
	while(scanf("%lf%d%d%d",&fund,&m,&n,&k)==4)
	{
		for(int i=0;i<n;i++)
		{
			cin>>all[i].name;
			scanf("%d%d",&s,&all[i].k);
			all[i].price.resize(m);
			for(int j=0;j<m;j++)
				scanf("%lf",&all[i].price[j]),all[i].price[j]*=s;
		}
		build_id_map();
		build_next();
		core_dp();
	}
	return 0;
}