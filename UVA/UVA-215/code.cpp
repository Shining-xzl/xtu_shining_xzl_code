/*
拓扑排序
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
char data[23][12][80];

struct node
{
	int x,y,flag;
	node (int a,int b,int c) : x(a),y(b),flag(c) {}
};
vector<node> d[23][12];
int map[23][12];
int degree[23][12];
vector<pair<int,int> > before[23][12];

void process(vector<node> &p,char *s,int &val,int X,int Y)//精华所在
{
	p.clear();
	val = 0;
	int x,y;
	for (int i = 0; s[i] != 0; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			x = s[i] - 'A';
			y = s[i+1] - '0';
			if(i == 0 || s[i-1] == '+')
				p.push_back(node(x,y,1));
			else p.push_back(node(x,y,-1));
			++degree[X][Y];
			before[x][y].push_back(pair<int,int>(X,Y));
			++i;
			// printf("***%d %d\n",x,y );
		}
		else if(s[i] >= '0' && s[i] <= '9')
		{
			if(i == 0 || s[i-1] == '+') y = 1;
			else y = -1;
			x = 0;
			while(s[i] >= '0' && s[i] <= '9')
			{
				x = (x*10) + (s[i]^48);
				++i;
			}
			// printf("%d\n",x*y );
			val += x * y;
		}
	}
	// printf("%d\n", val);
}

void work()
{
	pair<int,int> q[230];
	int l = 1,r = 0;
	int x,y,len,tx,ty;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			// printf("%d %d : %d\n",i,j,degree[i][j] );
			if(degree[i][j] == 0)
				q[++r] = pair<int,int>(i,j);
		}
	while(l <= r)
	{
		x = q[l].first;
		y = q[l++].second;
		len = d[x][y].size();
		for (int i = 0; i < len; ++i)
			map[x][y] += map[d[x][y][i].x][d[x][y][i].y] * d[x][y][i].flag; 
		len = before[x][y].size();
		for (int i = 0; i < len; ++i)
		{
			tx = before[x][y][i].first;
			ty = before[x][y][i].second;
			--degree[tx][ty];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			if(degree[tx][ty] == 0)
				q[++r] = pair<int,int>(tx,ty);
		}
	}
	// printf("%d\n", r);
	if(r == n*m) 
	{
		putchar(' ');
		for(int j = 0; j < m; ++j)
			printf("%6d",j);
		printf("\n");
		for (int i = 0; i < n; ++i)
		{
			putchar(i+'A');
			for (int j = 0; j < m; ++j)
				printf("%6d",map[i][j]);
			printf("\n");
		}
	}
	else 
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if(degree[i][j] != 0)
				{
					printf("%c%c: %s\n",i+'A',j+'0',data[i][j]);
				}
			
	}
}

int main()
{
	while(scanf("%d%d",&n,&m) == 2 && n && m)
	{
		memset(degree, 0, sizeof(degree));
		memset(data, 0, sizeof(data));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				before[i][j].clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				scanf("%s",data[i][j]);
				process(d[i][j],data[i][j],map[i][j],i,j);
			}
		work();
		printf("\n");
	}
	return 0;
} 
