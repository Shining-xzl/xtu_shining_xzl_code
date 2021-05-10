#include <cstdio>

using namespace std;
const int lim = 2e6+3;
#define lowbit(x) (x&(-x))

int ans[lim];
int l[lim],r[lim],n;

int get(int x)
{
	if(x == 0) return 1;
	int res = 0;
	while(x)
	{
		res += ans[x];
		x -= lowbit(x);
	}
	return res;
}

void add(int pos,int x)
{
	while(pos <= 2*n)
	{
		ans[pos] += x;
		pos += lowbit(pos);
	}
}

int main()
{
	int now = 0,x;
	bool flag = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		now += x;
		if(now != 0 && flag == 0)
		{
			add(1,1);
			add(i,-1);
			flag = 1;
		}
		if(l[now] == 0) l[now] = i;
		r[now] = i;
	}
	if(now == 0)
	{
		add(1,1);
		add(n+1,-1);
	}
	now = 0;
	flag = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		now += x;
		if(now != 0 && flag == 0)
		{
			add(1,1);
			add(i,-1);
			flag = 1;
		}
		if(l[now] != 0)
		{
			add(l[now]+i,1);
			add(r[now]+1+i,-1);
		}
	}
	if(now == 0)
	{
		add(1,1);
		add(n+1,-1);
	}
	for (int i = 0; i <= 2*n; ++i)
		printf("%d ", get(i));
	return 0;
}