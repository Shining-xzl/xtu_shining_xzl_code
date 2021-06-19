#include <stdio.h>

int R[1003],L[1003],val[1003];
int n,op = 1;

void dfs(int now,int X)
{
	if (X < val[now])
	{
		if (L[now] == -1)
		{
			L[now] = ++op;
			val[op] = X;
		}
		else dfs(L[now],X);
	}
	else
	{
		if (R[now] == -1)
		{
			R[now] = ++op;
			val[op] = X;
		}
		else dfs(R[now],X);
	}
}

void print(int now)
{
	if (now == -1) return;
	printf("%d ",val[now]);
	print(L[now]);
	print(R[now]);
}

int main()
{
	scanf("%d", &n);
	int x,i;
	for (i = 1; i <= n; ++i) R[i] = L[i] = -1;
	scanf("%d", &val[1]);
	for (i = 2; i <= n; ++i)
	{
		scanf("%d", &x);
		dfs(1,x);
	}
	print(1);
	return 0;
} 
