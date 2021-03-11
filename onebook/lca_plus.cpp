#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int lim=1e5+3;
struct edge
{
	int son,next,w;
	bool operator < (const edge &x) const 
	{
		return w<x.w;
	}
}s[lim*3],p[lim<<1];
int N,M,fa[lim],head[lim],op=0,dep[lim],f[lim][22];
int px[lim][22][2];
bool vis[lim*3];
long long ans=0;

#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
typedef set<int,greater<int> > SET;
typedef set<int,greater<int> >::iterator It;

int get_fa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=get_fa(fa[x]);
}

void make_edge(int a,int b,int w)
{
	op++;
	p[op].son=b;
	p[op].w=w;
	p[op].next=head[a];
	head[a]=op;
	op++;
	p[op].son=a;
	p[op].w=w;
	p[op].next=head[b];
	head[b]=op;
}

void process(int &M1,int &M2,int a,int b,int c,int d)
{
	SET sp;
	sp.insert(M1);
	sp.insert(M2);
	sp.insert(a);
	sp.insert(b);
	sp.insert(c);
	sp.insert(d);
	It it=sp.begin();
	M1=*it;
	it++;
	M2=*it;
}

void build_lca(int now,int fa)
{
	dep[now]=dep[fa]+1;
	f[now][0]=fa;
	for(int i=0;i<20;i++)
	{
		f[now][i+1]=f[f[now][i]][i];
		process(px[now][i+1][0],px[now][i+1][1],px[f[now][i]][i][1],px[f[now][i]][i][0],px[now][i][1],px[now][i][0]);
	}
	for(int v,i=head[now];i!=-1;i=p[i].next)
	{
		v=p[i].son;
		if(v==fa) continue;
		px[v][0][0]=p[i].w;
		px[v][0][1]=-1;
		build_lca(v,now);
	}
}

int lca(int a,int b,int w)
{
	int M1=0,M2=-1,x;
	if(dep[a]<dep[b]) x=a,a=b,b=x;
	for(int i=20;i>=0;i--)
	{
		if(dep[f[a][i]]>=dep[b])
		{
			process(M1,M2,px[a][i][0],px[a][i][1],-1,-1);
			a=f[a][i];
		}
	}
	if(a==b)
	{
		if(M1==w) return w-M2;
		else return w-M1;
	}
	for(int i=20;i>=0;i--)
		if(f[a][i]!=f[b][i])
		{
			process(M1,M2,px[a][i][0],px[a][i][1],px[b][i][0],px[a][i][1]);
			a=f[a][i];
			b=f[b][i];
		}
	process(M1,M2,px[a][0][0],px[a][0][1],px[b][0][0],px[a][0][1]);
	if(M1==w) return w-M2;
	else return w-M1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
		scanf("%d%d%d",&s[i].son,&s[i].next,&s[i].w);
	sort(s,s+M);
	for(int i=1;i<=N;i++)
		fa[i]=i;
	memset(head,-1,sizeof(head));
	int num=0,x,y;
	for(int i=0;i<M;i++)
	{
		x=get_fa(s[i].son);
		y=get_fa(s[i].next);
		if(x!=y)
		{
			fa[x]=y;
			vis[i]=1;
			make_edge(s[i].son,s[i].next,s[i].w);
			ans+=s[i].w;
			num++;
			if(num==N-1) break;
		}
	}
	build_lca(1,1);
	int temp=1e9;
	for(int i=0;i<M;i++)
		if(!vis[i])
			temp=Min(temp,lca(s[i].son,s[i].next,s[i].w));
	printf("%lld\n",ans+temp);
	return 0;
}