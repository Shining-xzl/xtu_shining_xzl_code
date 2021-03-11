#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int lim=3e5+3;

struct edge
{
	int son,next;
}s[lim<<2];
int w[lim],head[lim],op=0,n;
int son[lim],dep[lim],size[lim],top[lim],fa[lim],seg[lim],rev[lim];
int sumx,Maxx;
#define sgl seg[0]
#define MAX(x,y) ((x)>(y)?(x):(y))


void build(int a,int b)
{
	op++;
	s[op].son=b;
	s[op].next=head[a];
	head[a]=op;
}

// void make_tree(int now)
// {
// 	dep[now]=dep[fa[now]]+1;
// 	size[now]=1;
// 	for(int i=head[now],v;v=s[i].son,i!=-1;i=s[i].next)
// 	{
// 		if(v==fa[now]) continue;
// 		fa[v]=now;
// 		make_tree(v);
// 		size[now]+=size[v];
// 		if(size[v]>size[son[now]]) son[now]=v;
// 	}
// }

// void make_diff(int now)
// {
// 	int v=son[now];
// 	if(v)
// 	{
// 		seg[v]=++sgl;
// 		top[v]=top[now];
// 		rev[sgl]=v;
// 		make_diff(v);
// 	}
// 	for(int i=head[now];v=s[i].son,i!=-1;i=s[i].next)
// 		if(!top[v])
// 		{
// 			top[v]=v;
// 			seg[v]=++sgl;
// 			rev[sgl]=v;
// 			make_diff(v);
// 		}
// }

int q[lim];
void make_part()//BFS版
{
	int l=1,r=1,v,u;
	q[1]=1;
	while(l<=r)
	{
		u=q[l++];
		size[u]=1;
		dep[u]=dep[fa[u]]+1;
		for(int i=head[u];i!=-1;i=s[i].next)
			if(s[i].son!=fa[u])
			{
				fa[s[i].son]=u;
				q[++r]=s[i].son;
			}
	}
	for(int i=n;i>1;i--)
	{
		v=q[i];
		u=fa[v];
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
	int num;
	rev[1]=top[1]=1;
	for(int i=1;i<=n;i++)
	{
		num=1;
		u=rev[i];
		seg[u]=i;
		v=son[u];
		if(v)
		{
			top[v]=top[u];
			rev[i+num]=v;
			num+=size[v];
		}
		for(int j=head[u];j!=-1;j=s[j].next)
		{
			v=s[j].son;
			if(!top[v])
			{
				top[v]=v;
				rev[i+num]=v;
				num+=size[v];
			}
		}
	}
}

int Max[lim<<2],sum[lim<<2];
void build_tree(int id,int l,int r)
{
	if(l==r)
	{
		sum[id]=Max[id]=w[rev[l]];
		return;
	}
	int mid=l+r>>1;
	build_tree(id<<1,l,mid);
	build_tree(id<<1|1,mid+1,r);
	Max[id]=MAX(Max[id<<1],Max[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

void change(int id,int l,int r,int pos,int val)
{
	if(l==r)
	{
		Max[id]=sum[id]=val;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) change(id<<1,l,mid,pos,val);
	else change(id<<1|1,mid+1,r,pos,val);
	Max[id]=MAX(Max[id<<1],Max[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

void query(int id,int l,int r,int lx,int rx)
{
	if(l>rx||r<lx) return;
	if(l>=lx&&r<=rx)
	{
		sumx+=sum[id];
		Maxx=MAX(Maxx,Max[id]);
		return;
	}
	int mid=l+r>>1;
	query(id<<1,l,mid,lx,rx);
	query(id<<1|1,mid+1,r,lx,rx);
}

void swap(int &a,int &b)
{
	int x=a;
	a=b;
	b=x;
}

void ask(int a,int b)
{
	int ta=top[a],tb=top[b];
	while(ta!=tb)
	{
		if(dep[ta]<dep[tb]) swap(a,b),swap(ta,tb);
		query(1,1,n,seg[ta],seg[a]);
		a=fa[ta]; ta=top[a];
	}
	if(dep[a]>dep[b]) swap(a,b);
	query(1,1,n,seg[a],seg[b]);
}

void work()
{
	char p[20];
	int m,a,b;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d%d",p,&a,&b);
		if(p[0]=='C')
			change(1,1,n,seg[a],b);
		else 
		{
			sumx=0;
			Maxx=-1000000;
			ask(a,b);
			 if(p[1]=='M') printf("%d\n",Maxx);
			 else printf("%d\n",sumx);
		}
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d",&n);
	int a,b;
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		build(a,b);
		build(b,a);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	make_part();
	build_tree(1,1,n);
	work();
	return 0;
}
