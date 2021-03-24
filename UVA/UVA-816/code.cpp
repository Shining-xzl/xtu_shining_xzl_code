#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int inf=0x3f3f3f3f;

#define R(x) ((x+1)%4)
#define L(x) ((x+3)%4)

int start_x,start_y,end_x,end_y,dir,end_d;
char name[23];
vector<int> map[11][11][4];

struct path
{
	int x,y,dir;
}pre[11][11][4];

int dis[11][11][4];

struct node
{
	int x,y,d,dis;
	node(int a,int b,int x,int c):x(a),y(b),d(x),dis(c) {}
	bool operator < (const node &u) const
	{
		return dis>u.dis;
	}
};


inline int ask(const char &x)
{
	switch(x)
	{
		case 'E': return 0;
		case 'S': return 1;
		case 'W': return 2;
		case 'N': return 3;
		default : return -1;
	}
}

int num_p;
void print_path(int x,int y,int d)
{
	if(x == -1)
	{
		num_p++;
		printf("  (%d,%d)", start_x, start_y);
		return;
	}
	print_path(pre[x][y][d].x,pre[x][y][d].y,pre[x][y][d].dir);
	printf(" (%d,%d)", x, y);
	num_p++;
	if(num_p %10 == 0)
	{
		if(x == end_x && y==end_y && d == end_d)
			printf("\n");
		else printf("\n ");
		return;
	}
	if(x == end_x && y==end_y && d == end_d)
			printf("\n");
}

void spfa()
{
	memset(dis,inf,sizeof(dis));
	priority_queue<node> q;
	int x,y,d,len;
	end_d=-1;
	node temp(0,0,0,0);
	x = start_x + direction[dir][0];
	y = start_y + direction[dir][1];
	d = dir;
	dis[x][y][d] = 0;

	pre[x][y][d].x = -1;

	q.push(node(x,y,d,0));

	while(!q.empty())
	{
		temp = q.top();
		q.pop();
		if(temp.x == end_x && temp.y == end_y)
		{
			end_d = temp.d;
			break;
		}
		if(temp.dis > dis[temp.x][temp.y][temp.d]) continue;
		vector<int> &p = map[temp.x][temp.y][temp.d];
		for(int i = 0; i < p.size(); ++i)
		{
			x = temp.x + direction[ p[i] ][0];
			y = temp.y + direction[ p[i] ][1];
			d = p[i];
			len = temp.dis + 1;
			if(len < dis[x][y][d])
			{
				dis[x][y][d] = len;
				pre[x][y][d].x = temp.x;
				pre[x][y][d].y = temp.y;
				pre[x][y][d].dir = temp.d;
				q.push(node(x,y,d,len));
			}
		}
	}
	if(end_d != -1)
	{
		num_p=0;
		print_path(end_x,end_y,end_d);
	}
	else printf("  No Solution Possible\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char now[7];
	int x,y,in,out;
	while(scanf("%s",name) == 1)
	{
		if(!strcmp(name,"END")) break;
		for(int i = 0; i < 11; ++i)
			for(int j = 0; j < 11; ++j)
				for(int k = 0; k < 4; ++k)
					map[i][j][k].clear();
		scanf("%d %d", &start_x, &start_y);
		scanf(" %c", &now[0]); 
		dir = ask(now[0]);
		scanf("%d %d", &end_x, &end_y);
		while(scanf("%d", &x) == 1 && x)
		{
			scanf("%d", &y);
			while(scanf("%s" ,now) == 1)
			{
				if(now[0] == '*') break;
				in = ask(now[0]);
				for (int i = 1; now[i] != 0; ++i)
				{
					if(now[i] == 'L') out = L(in);
					else if(now[i] == 'R') out = R(in);
					else out = in;
					map[x][y][in].push_back(out);
				}
			}
		}
		printf("%s\n", name);
		spfa();
	}
	return 0;
} 
