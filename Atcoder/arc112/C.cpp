#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int lim = 1e5+3;
int son[lim],Next[lim];
int head[lim],op,res[lim],num[lim];
int n;
int odd[lim],even[lim];

void add(int a,int b)
{
	++op;
	son[op] = b;
	Next[op] = head[a];
	head[a] = op;
}

void dfs(int now)
{
	int son_count = 0;
	num[now] = 1;
	res[now] = 1;
	if(head[now] == -1) return;
	for (int i = head[now]; i != -1; i = Next[i])
	{
		++son_count;
		dfs(son[i]);
		num[now] += num[son[i]];
	}
	int len1 = 0,len0 = 0;
	int frist = 0,second = 0;
	for (int i = head[now]; i != -1; i = Next[i])
	{
		if(num[son[i]] & 1) odd[len1++] = res[son[i]];
		else even[len0++] = res[son[i]];
		if(son_count == 1)
		{
			res[now] +=res[son[i]];
			return;
		}
	}
	int op0 = 0;
	sort(odd,odd+len1);
	sort(even,even+len0);
	while(op0 < len0 && even[op0] < 0) frist += even[op0++];
	for (int i = 0; i < len1; ++i)
	{
		if(i & 1)
			second += odd[i];
		else frist += odd[i];
	}
	int temp = 0;
	while(op0 < len0) temp += even[op0++];
	if(len1 & 1) second += temp;
	else frist += temp;
	res[now] += frist - second;
}

int main()
{
	memset(head, -1, sizeof(head));
	int fa;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &fa);
		add(fa,i);
	}
	dfs(1);
	printf("%d\n", (res[1]+n)/2);
	return 0;
}