#include <cstdio>

using namespace std;

const int lim = 5e4+4;
int n,m;
int son[lim],next[lim],head[lim],op;
int dgree[lim];

int read()
{
	char c = getchar();
	int res = 0;
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

void init()
{
	scanf("%d %d", &n,&m);
	op = 0;
	for (int i = 0; i <= n; ++i)
		head[i] = -1, dgree[i] = 0;
	int a,b;
	while(m--)
	{
		b = read();
		a = read();
		dgree[b]++;
		son[++op] = b;
		next[op] = head[a];
		head[a] = op;
	}
}

int q[lim],ans[lim];
void work()
{
	long long sum = 0ll;
	int v,i,x,l = 1, r = 0;
	for (int i = 1; i <= n; ++i)
		if (dgree[i] == 0)
		{
			q[++r] = i;
			ans[i] = 888;
			sum += 888;
		}
	while(l <= r)
	{
		x = q[l++];
		i = head[x];
		while(i != -1)
		{
			v = son[i];
			dgree[v]--;
			if (dgree[v] == 0)
			{
				q[++r] = v;
				ans[v] = ans[x] + 1000;
				sum += (long long) ans[v];
			}
			i = next[i];
		}
	}
	if (r < n)
	{
		sum = 888 * n;
		for (int i = 1; i <= n; ++i)
			ans[i]= 888;
	}
	printf("%lld\n", sum);
	for (int i = 1; i < n; ++i)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		work();
	}	
	return 0;
}