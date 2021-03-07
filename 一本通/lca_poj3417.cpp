#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
int logN;
vector< vector<int> > node,f;
vector< int > dep,val;


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
	int len=node[now].size(),v;
	for(int i=0;i<len;i++)
	{
		v=node[now][i];
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
	int len=node[now].size(),v;
	for(int i=0;i<len;i++)
	{
		v=node[now][i];
		if(v==fa) continue;
		dfs(v,now);
		val[now]+=val[v];
	}
}

void initail()
{
	read(N);
	read(M);
	logN=log2(N)+1;
	node.resize(N+2,vector<int>(0) );
	f.resize(N+2,vector<int>(logN+2) );
	dep.resize(N+2,0);
	val.resize(N+2,0);
	int a,b;
	for(int i=1;i<N;i++)
	{
		read(a);
		read(b);
		node[a].push_back(b);
		node[b].push_back(a);
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
	// freopen("in.txt","r",stdin);
	initail();
	solve();
	return 0;
}