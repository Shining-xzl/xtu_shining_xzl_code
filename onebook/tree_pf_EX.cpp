#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int lim=1e5+3;
int n,q;
int w[lim],c[lim],head[lim],op=0;

struct edge
{
	int son,next;
}s[lim<<1];

int dep[lim],size[lim],father[lim],son[lim];
int seg[lim],rev[lim],top[lim];
#define sgl seg[0]
#define MAX(x,y) ((x)>(y)?(x):(y))

struct tree
{
	int sum,Max;
	int lson,rson;
	tree()
	{
		lson=rson=0;
	}
}p[lim<<5];
int Num=0,cID[lim];

void build(int a,int b)
{
	op++;
	s[op].son=b;
	s[op].next=head[a];
	head[a]=op;
}

void dfs1(int now)
{
	dep[now]=dep[father[now]]+1;
	size[now]=1;
	for(int i=head[now],v;i!=-1,v=s[i].son;i=s[i].next)
	{
		if(v==father[now]) continue;
		father[v]=now;
		dfs1(v);
		size[now]+=size[v];
		if(size[son[now]]<size[v])
			son[now]=v;
	}
}

void dfs2(int now)
{
	int v=son[now];
	if(v)
	{
		seg[v]=++sgl;
		rev[sgl]=v;
		top[v]=top[now];
		dfs2(v);
	}
	for(int i=head[now];v=s[i].son,i!=-1;i=s[i].next)
		if(!top[v])
		{
			seg[v]=++sgl;
			rev[sgl]=v;
			top[v]=v;
			dfs2(v);
		}
}

void initail()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&c[i]);
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		build(a,b);
		build(b,a);
	}
	dfs1(1);
	sgl=seg[1]=rev[1]=top[1]=1;
	dfs2(1);
}

void change(int &id,int l,int r,int pos,int val)
{
	if(id==0) id=++Num;
	if(l==r)
	{
		p[id].sum=p[id].Max=val;
		return;
	}
	int mid=l+r>>1;
	if(mid>=pos) change(p[id].lson,l,mid,pos,val);
	else change(p[id].rson,mid+1,r,pos,val);
	p[id].sum=p[p[id].lson].sum+p[p[id].rson].sum;
	p[id].Max=MAX(p[p[id].lson].Max,p[p[id].rson].Max);
}

void swap(int &a,int &b)
{
	int x=a;a=b;b=x;
}

int tmax,tsum;
void query(int id,int l,int r,int xl,int xr)
{
	if(id==0||l>xr||r<xl) return;
	if(l>=xl&&r<=xr)
	{
		tmax=MAX(tmax,p[id].Max);
		tsum+=p[id].sum;
		return;
	}
	int mid=l+r>>1;
	query(p[id].lson,l,mid,xl,xr);
	query(p[id].rson,mid+1,r,xl,xr);	
}

void ask(int a,int b,bool flag)
{
	int ta=top[a],tb=top[b],C=c[a];
	int Tmax=0,Tsum=0;
	while(ta!=tb)
	{
		if(dep[ta]<dep[tb]) swap(ta,tb),swap(a,b);
		tmax=tsum=0;
		query(cID[C],1,n,seg[ta],seg[a]);
		Tmax=MAX(Tmax,tmax);
		Tsum+=tsum;
		a=father[ta];ta=top[a];
	}
	tmax=tsum=0;
	if(dep[a]>dep[b]) swap(a,b);
	query(cID[C],1,n,seg[a],seg[b]);
	Tmax=MAX(Tmax,tmax);
	Tsum+=tsum;
	if(flag) printf("%d\n",Tmax);
	else printf("%d\n",Tsum);
}

void work()
{
	char Q[3];
	int a,b;
	while(q--)
	{
		scanf("%s%d%d",Q,&a,&b);
		switch(Q[1])
		{
			case 'C' : change(cID[c[a]],1,n,seg[a],0); change(cID[b],1,n,seg[a],w[a]); c[a]=b;break;
			case 'W' : change(cID[c[a]],1,n,seg[a],b); w[a]=b; break;
			case 'S' : ask(a,b,0); break;
			case 'M' : ask(a,b,1); break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	initail();
	for(int i=1;i<=n;i++)
		change(cID[c[i]],1,n,seg[i],w[i]);
	work();
	return 0;
}