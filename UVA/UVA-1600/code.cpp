#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dis[23][23][23];

bool map[23][23];
int n,m,k;

bool check(int x,int y)
{
	if(x < 1 || x > n || y > m || y < 1) return false;
	else return true; 
}

struct node
{
	int x,y,k,dis;
	node(int a,int b,int o,int c) : x(a),y(b),k(o),dis(c) {}
	bool operator < (const node &u) const
	{
		return dis > u.dis;
	}
};

void spfa()
{
	memset(dis, inf, sizeof(dis));
	priority_queue< node > q;
	dis[1][1][0] = 0;
	q.push(node(1,1,0,0));
	int x,y,lk,len,tx,ty,tk;
	while(!q.empty())
	{
		x = q.top().x;
		y = q.top().y;
		lk = q.top().k;
		len = q.top().dis;
		q.pop();
		if(len > dis[x][y][lk]) continue;
		for (int i = 0; i < 4; ++i)
		{
			tx = x + direction[i][0];
			ty = y + direction[i][1];
			if(!check(tx,ty)) continue;
			if(map[tx][ty] == 0) tk = 0;
			else tk = lk + 1;
			if(tk <= k && len + 1 < dis[tx][ty][tk])
			{
				dis[tx][ty][tk] = len + 1;
				q.push(node(tx,ty,tk,dis[tx][ty][tk]));
			}
		}
	}
	int Min = inf;
	for (int i = 0; i <= k; ++i)
		if(dis[n][m][i] < Min) 
			Min = dis[n][m][i];
	printf("%d\n", Min == inf ? -1 : Min);
}

int main()
{
	int time;
	scanf("%d", &time);
	while(time--)
	{
		scanf("%d %d %d", &n,&m,&k);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &map[i][j]);
		spfa();
	}
	return 0;
} 
