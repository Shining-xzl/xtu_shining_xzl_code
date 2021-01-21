#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int LIM=100003;
int n;
bool visited[LIM];
vector<int> son[LIM];

void rbuild_dfs(int now)
{
	visited[now]=true;
	vector<int> me;
	int len=son[now].size();
	for(int i=0;i<len;i++)
	{
		if(!visited[son[now][i]])
		{
			me.push_back(son[now][i]);
			rbuild_dfs(son[now][i]);
		}
	}
	son[now]=me;
}

void initail()
{
	int a,b,temp;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
		son[i].clear();
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		son[a].push_back(b);
		son[b].push_back(a);	
	}
	rbuild_dfs(1);
	scanf("%d",&temp);
}

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)==1&&n!=-1)
	{
		initail();
	}
	return 0;
}