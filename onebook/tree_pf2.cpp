#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int lim=1e5+4;
int dep[lim],seg[lim],rev[lim],son[lim];
int father[lim],size[lim],top[lim];
int n,m,op=0,w[lim],head[lim],end[lim];

struct edge
{
	int v,next;	
}s[lim<<1];

void build(int a,int b)
{
	op++;
	s[op].v=b;
	s[op].next=head[a];
	head[a]=op;
}

#define sgl seg[0]
void dfs1(int now)
{
	dep[now]=dep[father[now]]+1;
	size[now]=1;
	for(int i=head[now],v;i!=-1;i=s[i].next)
	{
		v=s[i].v;
		if(v==father[now]) continue;
		father[v]=now;
		dfs1(v);
		size[now]+=size[v];
		if(size[v]>size[son[now]]) 
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
	for(int i=head[now];i!=-1;i=s[i].next)
	{
		v=s[i].v;
		if(!top[v])
		{
			seg[v]=++sgl;
			rev[sgl]=v;
			top[v]=v;
			dfs2(v);
		}
	}
	end[now]=sgl;
}

void make_part()
{
	dfs1(1);
	top[1]=rev[1]=seg[1]=sgl=1;
	dfs2(1);
}

long long sum[lim<<2],tag[lim<<2];

void make_tree(int id,int l,int r)
{
	if(l==r)
	{
		sum[id]=w[rev[l]];
		return;
	}
	int mid=(l+r)>>1;
	make_tree(id<<1,l,mid);
	make_tree(id<<1|1,mid+1,r);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

void change(int id,int l,int r,int lx,int rx,LL val)
{
	if(l>rx||r<lx) return;
	if(l>=lx&&r<=rx)
	{
		tag[id]+=val;
		sum[id]+=val*(r-l+1);
		return;
	}
	int num=r-l+1,mid=(l+r)>>1;
	if(lx>l) num-=lx-l;
	if(rx<r) num-=r-rx;
	sum[id]+=(LL)num*val;
	change(id<<1,l,mid,lx,rx,val);
	change(id<<1|1,mid+1,r,lx,rx,val);
}

long long query(int id,int l,int r,int lx,int rx)
{
	if(l>rx||r<lx) return 0;
	if(l>=lx&&r<=rx) return sum[id];
	int num=r-l+1,mid=(l+r)>>1;
	if(lx>l) num-=lx-l;
	if(rx<r) num-=r-rx;
	long long ans=(LL)num*tag[id];
	ans+=query(id<<1,l,mid,lx,rx);
	ans+=query(id<<1|1,mid+1,r,lx,rx);
	return ans;
}

void swap(int &a,int &b)
{
	int x=a;
	a=b;b=x;
}

long long ask(int a,int b)
{
	int ta=top[a],tb=top[b];
	long long ans=0;
	while(ta!=tb)
	{
		if(dep[ta]<dep[tb]) swap(a,b),swap(ta,tb);
		ans+=query(1,1,n,seg[ta],seg[a]);
		a=father[ta];
		ta=top[a];
	}
	if(dep[a]>dep[b]) swap(a,b);
	ans+=query(1,1,n,seg[a],seg[b]);
	return ans;
}

void work()
{
	int x,a,b,con=0;
	while(m--)
	{
		scanf("%d%d",&x,&a);
		if(x==3) 
			printf("%lld\n",ask(1,a));
		else 
		{
			scanf("%d",&b);
			if(x==1) change(1,1,n,seg[a],seg[a],(LL)b);
			else change(1,1,n,seg[a],end[a],(LL)b);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	int a,b;
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		build(a,b);
		build(b,a);
	}
	make_part();
	make_tree(1,1,n);
	work();
	return 0;
}
