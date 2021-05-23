#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 1e5+4;

int head[lim],op,sg[lim];
struct edge
{
	int v;
	int next;	
}s[lim<<1];
int n;

void add(int a,int b)
{
	op++;
	s[op].v = b;
	s[op].next = head[a];
	head[a] = op;
}

void init()
{
	memset(head, -1, sizeof(head));
	op = 0;
	scanf("%d",&n);
	int a,b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &a,&b);
		add(a,b);
		add(b,a);
	}
}

void dfs(int now,int fa)
{
	int i = head[now],v;
	sg[now] = 0;

	while(i != -1)
	{
		v = s[i].v;
		if(v != fa)
		{
			dfs(v,now);
			sg[now] ^= (sg[v] + 1);
		}
		i = s[i].next;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		dfs(1,0);
		if(sg[1] == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}