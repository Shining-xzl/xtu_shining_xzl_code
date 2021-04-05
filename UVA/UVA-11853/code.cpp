/*
思维
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n;
struct pos
{
	double x,y,r;
}p[1003];
double ans_yW,ans_yE;
bool vis[1003];
vector<int> son[1003];

bool check(int i,int j)
{
	double x = p[i].x - p[j].x;
	double y = p[i].y - p[j].y;
	return (x*x + y*y) <= (p[i].r + p[j].r)*(p[i].r + p[j].r);
}

bool dfs(int now)
{
	vis[now] = 1;
	double y;
	if(p[now].x - p[now].r <= 0)
	{
		y = p[now].r * p[now].r;
		y -= p[now].x * p[now].x;
		y = sqrt(y);
		y = p[now].y - y;
		if(y < ans_yW) ans_yW = y;
	}
	if(p[now].x + p[now].r >= 1000.00)
	{
		y = p[now].r * p[now].r;
		y -= (1000 - p[now].x) * (1000 - p[now].x);
		y = sqrt(y);
		y = p[now].y - y;
		if(y < ans_yE) ans_yE = y;
	}
	if(p[now].y - p[now].r <= 0) return 1;
	int v,len = son[now].size();
	for (int i = 0; i < len; ++i)
	{
		v = son[now][i];
		if(!vis[v] && dfs(v))
			return 1;
	}
	return 0;
}

bool have_ans()
{
	memset(vis, 0, sizeof(vis));
	ans_yE = ans_yW = 1000.0;
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i] && p[i].y + p[i].r >= 1000.0)
		{
			if(dfs(i)) return 0;
		}
	}
	return 1;
}

int main()
{
	while(scanf("%d",&n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			son[i].clear();
			scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].r);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if(i != j && check(i,j))
				{
					son[i].push_back(j);
					son[j].push_back(i);
				}
		if(!have_ans()) printf("IMPOSSIBLE\n");
		else
		{
			printf("%.2lf %.2lf %.2lf %.2lf\n",0.00,ans_yW,1000.00,ans_yE);
		}
	}
	return 0;
} 
