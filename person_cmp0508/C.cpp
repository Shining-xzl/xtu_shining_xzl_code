#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int lim = 1e5+3;

struct fbos
{
	int l,r;
	operator < (const fbos &x) const 
	{
		return r > x.r;
	}
};

int Next[lim];
bool vis[lim];
int ans[lim];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,now,a,b;
	scanf("%d %d", &n, &m);
	memset(Next, -1, sizeof(Next));
	while(m--)
	{
		scanf("%d %d", &a,&b);
		Next[a] = b;
	}
	fbos temp;
	queue<fbos> out;
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			temp.l = i;
			now = i;
			while(now != -1)
			{
				vis[now] = 1;
				temp.r = now;
				now = Next[now];
			}
			// printf("%d %d\n",temp.l,temp.r );
			out.push(temp);
		}
	}
	priority_queue<fbos> in;
	while(!out.empty())
	{
		if (in.empty() || in.top().r > out.front().l ) in.push(out.front());
		else
		{
			temp = in.top(); in.pop();
			Next[temp.r] = out.front().l;
			temp.r = out.front().r;
			in.push(temp);
		}
		out.pop();
	}
	a = 0;
	while(!in.empty())
	{
		++a;
		now = in.top().l; in.pop();
		while(now != -1)
		{
			ans[now] = a;
			now = Next[now];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}