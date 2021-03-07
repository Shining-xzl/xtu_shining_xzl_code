#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int N,M;
int logN;
const int LIM=1e5+3;
struct Node
{
	int son,next;
}s[LIM<<1];

int head[LIM],op=0,f[LIM][22],dep[LIM],val[LIM];

template <typename READ>
void read(READ &a)
{
	a=0;
	char c=getchar();
	bool flag=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
	if(flag) a=-a;
}

template <typename WRITE>
void write(WRITE a)
{
	char c[30],len=0;
	if(a<0) putchar('-'),a=-a;
	do
	{
		c[len++]=a%10+48;
		a/=10;
	}while(a>0);
	while(len--) putchar(c[len]);
}

void build(int now,int fa)
{
	dep[now]=dep[fa]+1;
	f[now][0]=fa;
	for(int i=0;i<logN;i++)
		f[now][i+1]=f[f[now][i]][i];
	int v;
	for(int i=head[now];i!=-1;i=s[i].next)
	{
		v=s[i].son;
		if(v==fa) continue;
		build(v,now);
	}
}

int LCA(int a,int b)
{
	int x;
	if(dep[a]<dep[b])
	{
		x=a;
		a=b;
		b=x;
	}
	for(int i=logN;i>=0;i--)
		if(dep[f[a][i]]>=dep[b])
			a=f[a][i];
	if(a==b) return a;
	for(int i=logN;i>=0;i--)
	{
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}

void dfs(int now,int fa)
{
	int v;
	for(int i=head[now];i!=-1;i=s[i].next)
	{
		v=s[i].son;
		if(v==fa) continue;
		dfs(v,now);
		val[now]+=val[v];
	}
}

void build_node(int a,int b)
{
	op++;
	s[op].son=b;
	s[op].next=head[a];
	head[a]=op;
	op++;
	s[op].son=a;
	s[op].next=head[b];
	head[b]=op;
}

void initail()
{
	read(N);
	read(M);
	logN=log2(N)+1;
	memset(head,-1,sizeof(head));
	int a,b;
	for(int i=1;i<N;i++)
	{
		read(a);
		read(b);
		build_node(a,b);
	}
	build(1,0);
	for(int i=0;i<M;i++)
	{
		read(a);
		read(b);
		val[a]++;
		val[b]++;
		val[LCA(a,b)]-=2;
	}
	dfs(1,0);
}

void solve()
{
	long long ans=0;
	for(int i=2;i<=N;i++)
	{
		if(val[i]==1) ans++;
		else if(val[i]==0) ans+=M;
	}
	write(ans);
	putchar('\n');
}

int main()
{
	//freopen("in.txt","r",stdin);
	initail();
	solve();
	return 0;
}