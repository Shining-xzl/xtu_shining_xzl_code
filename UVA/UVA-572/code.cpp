#include <cstdio>
#include <cstring>
using namespace std;
const int op[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m;
char map[102][102];
bool vis[102][102];

void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m||vis[x][y]) return;
	vis[x][y]=true;
	int xx,yy;
	for(int i=0;i<8;i++)
	{
		xx=x+op[i][0];
		yy=y+op[i][1];
		if(map[xx][yy]=='@')
			dfs(xx,yy);
	}

}

int main()
{
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int ans;
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		for(int i=1;i<=n;++i)
			scanf("%s",map[i]+1);
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(!vis[i][j]&&map[i][j]=='@')
				{
					dfs(i,j);
					ans++;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
} 
