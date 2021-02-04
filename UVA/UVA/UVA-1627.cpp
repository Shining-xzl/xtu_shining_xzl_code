#include <bits/stdc++.h>

using namespace std;
const int LIM=102;
int n;
bool f[103][103],flag;
int visited[103],difnum[103],ind;
vector<int> son[103],num0[103],num1[103];
bool dp[102][205];
bool pre[102][205];
void find_dfs(int now,int k)
{
	if(!flag) return;
	visited[now]=k;
	difnum[ind]=( k&1 ? difnum[ind]+1:difnum[ind]-1 );
	if(k==1) num1[ind].push_back(now);
	else num0[ind].push_back(now);
	int len=son[now].size(),x;
	for(int i=0;i<len;i++)
	{
		x=son[now][i];
		if(visited[x]==-1)
			find_dfs(x,k^1);
		else if(visited[now]==visited[x])
			flag=0;
		if(!flag) return;
	}
}

void initail()
{
	int x;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		while(scanf("%d",&x)&&x)
			f[i][x]=1;
	for(int i=1;i<=n;i++)
	{
		son[i].clear();
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(f[i][j]==0||f[j][i]==0)
				son[i].push_back(j);
		}
	}
	flag=1;
	ind=0;
	memset(visited,-1,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==-1)
		{
			ind++;
			difnum[ind]=0;
			num1[ind].clear();
			num0[ind].clear();
			find_dfs(i,1);
		}
	}
}

void get_ans_dp()
{
	memset(dp,0,sizeof(dp));
	dp[0][LIM]=1;
	int a,temp;
	for(int i=1;i<=ind;i++)
	{
		for(int j=0;j<205;j++)
		{
			a=j+difnum[i];
			if(a>=0&&a<205&&dp[i-1][a])
				dp[i][j]=1,pre[i][j]=0;
			 a=j-difnum[i];
			if(a>=0&&a<205&&dp[i-1][a])
				dp[i][j]=1,pre[i][j]=1;
		}
	}
	// printf("%d\n",difnum[2]);
	vector<int> ax,bx;
	for(int i=0;i<=100;i++)
		if(dp[ind][LIM+i])
		{
			a=i;
			i=i+LIM;
			temp=ind;
			while(temp)
			{
				// printf("*%d\n",i);
				if(pre[temp][i])
				{
					ax.insert(ax.end(),num1[temp].begin(),num1[temp].end());
					bx.insert(bx.end(),num0[temp].begin(),num0[temp].end());
					i-=difnum[temp];
				}
				else
				{
					bx.insert(bx.end(),num1[temp].begin(),num1[temp].end());
					ax.insert(ax.end(),num0[temp].begin(),num0[temp].end());
					i+=difnum[temp];
				}
				temp--;
			}
			break;
		}
	// printf("%d\n",a);
	sort(ax.begin(),ax.end());
	sort(bx.begin(),bx.end());
	printf("%llu",ax.size());
	for(unsigned i=0;i<ax.size();i++)
		printf(" %d",ax[i]);
	printf("\n");
	printf("%llu",bx.size());
	for(unsigned i=0;i<bx.size();i++)
		printf(" %d",bx[i]);
	printf("\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		if(!flag) printf("No solution\n");
		else get_ans_dp();
		printf("\n");
	}
	return 0;
}