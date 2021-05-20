#include <stdio.h>
#include <string.h>
char p[504][504];
int dgree[504];
int ans[1504],op = 0;
int n,in;

void dfs(int now)
{
	for (int i = 1; i <= 500; ++i)
		if(p[now][i] > 0)
		{
			--p[now][i];
			--p[i][now];
			dfs(i);
		}
	ans[++op] = now;
}

int main()
{
	int a,b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a,&b);
		++dgree[a];
		++dgree[b];
		p[a][b]++;
		p[b][a]++;
	}
	in = 1;
	for (int i = 1; i <= 500; ++i)
		if(dgree[i] & 1) 
		{
			in = i;
			break;
		}
	dfs(in);
	for (int i = op; i > 0; --i)
		printf("%d\n", ans[i]);
	return 0;
}