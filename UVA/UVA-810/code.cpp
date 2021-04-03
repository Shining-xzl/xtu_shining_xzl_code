/*
论英语的重要性
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int to[7][7];
int n,m;
int sX,sY,u,f;
int map[12][12];

void span(int &u,int &f,int i)
{
	int t;
	if(i == 0)
	{
		t = f;
		f = 7 - u;
		u = t;
	}
	else if(i == 1)
	{
		t = u;
		u = 7 - f;
		f = t;
	}
	else if(i == 2)
	{
		u = 7 - to[u][f];
	}
	else u = to[u][f];
}
int vis[12][12][7][7];

struct node
{
	int x,y,u,f;
	int pre;
}q[10003];
vector< pair<int,int> > ans;
void print(int pos)
{
	if(q[pos].pre == -1)
	{
		ans.push_back(pair<int,int>(q[pos].x,q[pos].y) );
		return;
	}
	print(q[pos].pre);
	ans.push_back(pair<int,int>(q[pos].x,q[pos].y) );
}

void bfs()
{
	memset(vis,0,sizeof(vis));
	node temp;
	int x,y,xx,yy,U,F,xu,xf,l = 1,r = 0;
	temp.x = sX; temp.y = sY; temp.u = u; temp.f = f; temp.pre = -1;
	q[++r] = temp;
	while(l <= r)
	{
		temp = q[l++];
		x = temp.x; y = temp.y; U = temp.u; F = temp.f;
		for (int i = 0; i < 4; ++i)
		{
			xx = x + direction[i][0];
			yy = y + direction[i][1];
			xu = U; xf = F;
			span(xu,xf,i);
			if(xx < 1 || xx > n || yy < 1 || yy > m || map[xx][yy] == 0 || vis[xx][yy][xu][xf]) continue;
			if(U == map[xx][yy] || map[xx][yy] == -1)
			{	
				vis[xx][yy][xu][xf] = 1;
				temp.x = xx; temp.y = yy; temp.u = xu; temp.f = xf; temp.pre = l - 1;
				q[++r] = temp;
				if(xx == sX && yy == sY)
				{
					ans.clear();
					print(r);
					l = ans.size();
					for(int i = 0; i < l; ++i)
					{
						if(i%9 == 0) printf("\n  ");
						printf("(%d,%d)",ans[i].first,ans[i].second);
						if(i != l-1) putchar(',');
					}
					printf("\n");
					return;
				}
			}
		}
	}
	printf("\n  No Solution Possible\n");
}

int main()
{
	to[1][2] = 4; to[1][3] = 2; to[1][4] = 5; to[1][5] = 3;
	to[2][1] = 3; to[2][3] = 6; to[2][4] = 1; to[2][6] = 4;
	to[3][1] = 5; to[3][2] = 1; to[3][5] = 6; to[3][6] = 2;
	to[4][1] = 2; to[4][2] = 6; to[4][5] = 1; to[4][6] = 5;
	to[5][1] = 4; to[5][3] = 1; to[5][4] = 6; to[5][6] = 3;
	to[6][2] = 3; to[6][3] = 5; to[6][4] = 2; to[6][5] = 4;
	char name[24];
	while(scanf("%s",name) == 1 && strcmp(name,"END"))
	{
		scanf("%d %d %d %d %d %d",&n,&m,&sX,&sY,&u,&f);
		for (int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%d",&map[i][j]);
		printf("%s", name);
		bfs();
	}
	return 0;
}