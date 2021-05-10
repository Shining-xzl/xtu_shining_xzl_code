#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;
const int lim = 5003;
struct tree
{
	int next,son;	
}s[lim<<1];
int head[lim],op = 0;
int n;
LL num[lim],gnum[lim];
LL ansa = 0,ansb = 0;

LL fpow(LL a,LL p)
{
	if(p == 0) return 1;
	LL res = fpow(a,p/2);
	res = res * res % MOD;
	if(p&1) res = res * a % MOD;
	return res;
}

void add(int a,int b)
{
	op++;
	s[op].son = b;
	s[op].next = head[a];
	head[a] = op;
}

void init()
{
	memset(head, -1, sizeof(head));
	op = 0;
	ansa = 0,ansb = 0;
}


void dfs(int now,int fa)
{
	int v,i;
	i = head[now];
	num[now] = 1;
	while(i != -1)
	{
		v = s[i].son;
		if(v != fa)
		{
			dfs(v,now);
			num[now] = (num[now] * (num[v] + 1)) % MOD;
		}
		i = s[i].next;
	}
	i = head[now];
	gnum[now] = num[now];
	while(i != -1)
	{
		v = s[i].son;
		if(v != fa)
		{
			gnum[now] += num[now] * gnum[v] % MOD * fpow(num[v]+1,MOD-2) % MOD;
			/*
			gnum 数组实际上就是点的数量，所谓贡献，其实就是每个点出现的次数和（因为分母相同）
			num[now]/(num[v]+1) 是选择的数量，gnum[v]是存在贡献点的数量
			组合数学
			*/
			if(gnum[now] >= MOD) gnum[now] -= MOD;
		}
		i = s[i].next;
	}
	ansa += gnum[now];
	if(ansa >= MOD) ansa -= MOD;
	ansb += num[now];
	if(ansb >= MOD) ansb -= MOD;
}

int main()
{
	int x;
	while(scanf("%d",&n) == 1)
	{
		init();
		for (int i = 2; i <= n; ++i)
		{
			scanf("%d",&x);
			add(x,i); add(i,x);	
		}
		dfs(1,0);
		printf("%lld\n", ansa * fpow(ansb, MOD-2) % MOD);
	}
	return 0;
}