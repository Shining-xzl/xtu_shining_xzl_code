#include <cstdio>
#include <cstring>
using namespace std;

const int lim = 1003;

int R[lim],L[lim],val[lim],dep[lim],op;

void build(int id,int x)
{
	if (x < val[id])
	{
		if (L[id] == -1)
		{
			L[id] = ++op;
			val[op] = x;
		}
		else build(L[id],x);
	}
	else
	{
		if (R[id] == -1)
		{
			R[id] = ++op;
			val[op] = x;
		}
		else build(R[id],x);
	}
}

#define Max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)>0?(x):-(x))
bool check(int now)
{
	if (now == -1) return 1;
	if (L[now] == R[now])
	{
		dep[now] = 1;
		return 1;
	}
	else
	{
		if (check(R[now]) == 0 || check(L[now]) == 0)
			return 0;
		if (R[now] == -1) 
		{
			if (dep[L[now]] != 1) return 0;
			dep[now] = 2;
		}
		else if (L[now] == -1)
		{
			if (dep[R[now]] != 1) return 0;
			dep[now] = 2;
		}
		else
		{
			if (abs(dep[R[now]] - dep[L[now]]) > 1) return 0;
			dep[now] = Max(dep[R[now]] , dep[L[now]]) + 1;
		}
		return 1;
	}
}

void initail()
{
	memset(R, -1, sizeof(R));
	memset(L, -1, sizeof(L));
	memset(dep, 0, sizeof(dep));
	int n,x;
	op = 1;
	scanf("%d", &n);
	scanf("%d", &val[1]);
	while(--n)
	{
		scanf("%d", &x);
		build(1,x);
	}
	if (check(1)) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		initail();
	}
	return 0;
}