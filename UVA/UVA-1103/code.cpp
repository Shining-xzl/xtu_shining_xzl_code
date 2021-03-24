#include <cstdio>
#include <cstring>
using namespace std;
const int op[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
const char p[6]={'A','D','J','K','S','W'};
int n,m;
int map[203][203];
bool vis[203][203];
int stack[40003],len;
int res[7];
#define Max(x,y) ((x)>(y)?(x):(y))

void process(int x,int y,const char &a)
{
	int num;
	if(a>='0'&&a<='9') num=a-'0';
	else num=a-'a'+10;
	map[x][y]=(num>>3)&1;
	map[x][y+1]=(num>>2)&1;
	map[x][y+2]=(num>>1)&1;
	map[x][y+3]=num&1;
}

int mark(int x,int y,int k,int s)
{
	if(x<1||x>n||y<1||y>m) return -1;
	vis[x][y]=1;
	map[x][y]=k;
	int xx,yy,ans=-1;
	for(int i=0;i<8;i++)
	{
		xx=x+op[i][1];
		yy=y+op[i][0];
		if(!vis[xx][yy]&&map[xx][yy]==s)
			mark(xx,yy,k,s);
		ans=Max(ans,map[xx][yy]);
	}
	return ans;
}

int main()
{
	char s[56];
	int cas=0;
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(int j=0;j<m;j++)
				process(i,j*4+1,s[j]);
		}
		m*=4;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i][1]&&map[i][1]==0)
				mark(i,1,-1,0);
			if(!vis[i][m]&&map[i][m]==0)
				mark(i,m,-1,0);
		}
		for(int i=1;i<=m;++i)
		{
			if(!vis[1][i]&&map[1][i]==0)
				mark(1,i,-1,0);
			if(!vis[n][i]&&map[n][i]==0)
				mark(n,i,-1,0);
		}
		len=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(!vis[i][j]&&map[i][j]==1)
				{
					stack[++len]=0;
					mark(i,j,len,1);
				}
			}
		int temp;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(!vis[i][j]&&map[i][j]==0)
				{
					temp=mark(i,j,0,0);
					stack[temp]++;
				}
			}
		memset(res,0,sizeof(res));
		for(int i=1;i<=len;i++)
		{
			switch(stack[i])
			{
				case 1:res[0]++;break;
				case 5:res[1]++;break;
				case 3:res[2]++;break;
				case 2:res[3]++;break;
				case 4:res[4]++;break;
				case 0:res[5]++;break;
			}
		}
		printf("Case %d: ",++cas);
		for(int i=0;i<6;i++)
			for(int j=0;j<res[i];j++)
				printf("%c",p[i]);
		printf("\n");
	}
	return 0;
} 
