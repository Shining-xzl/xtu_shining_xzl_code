#include <cstdio>
#include <cstring>
using namespace std;
const int lim=1e5+3;
int son[lim],size[lim],end[lim],top[lim],dep[lim],seg[lim],rev[lim],father[lim];
int n,m,head[lim],op=0,dfn=0;
struct edge
{
	int son,next;
}s[lim];

int sum[lim<<2],tag[lim<<2];

void build(int a,int b)
{
	op++;
	s[op].son=b;
	s[op].next=head[a];
	head[a]=op;
}

void dfs1(int now)
{
	size[now]=1;
	dep[now]=dep[father[now]]+1;
	int sonx=0,v;
	for(int i=head[now];i!=-1;i=s[i].next)
	{
		v=s[i].son;
		father[v]=now;
		dfs1(v);
		size[now]+=size[v];
		if(sonx<size[v])
		{
			son[now]=v;
			sonx=size[v];
		}
	}
}

void dfs2(int now)
{
	int v=son[now];
	if(v)
	{
		seg[v]=++dfn;
		rev[dfn]=v;
		top[v]=top[now];
		dfs2(v);
	}
	for(int i=head[now];i!=-1;i=s[i].next)
	{
		v=s[i].son;
		if(v!=son[now])
		{
			seg[v]=++dfn;
			rev[dfn]=v;
			top[v]=v;
			dfs2(v);
		}
	}
	end[now]=dfn;
}

void make_part()
{
	dfs1(0);
	seg[0]=1;
	rev[1]=0;
	dfn=1;
	dfs2(0);
}

void updata(int id,int l,int r)
{
	int L=id<<1,R=id<<1|1,mid=l+r>>1;
	if(tag[id]==-1) return;
	tag[L]=tag[R]=tag[id];
	sum[L]=(mid-l+1)*tag[id];
	sum[R]=(r-mid)*tag[id];
	tag[id]=-1;
}

int query(int id,int l,int r,int lx,int rx)
{
	if(l>rx||r<lx) return 0;
	if(l>=lx&&r<=rx) return sum[id];
	int mid=(l+r)>>1;
	updata(id,l,r);
	return query(id<<1,l,mid,lx,rx)+query(id<<1|1,mid+1,r,lx,rx);
}

void change(int id,int l,int r,int lx,int rx,int val)
{
	if(l>rx||r<lx) return;
	if(l>=lx&&r<=rx)
	{
		tag[id]=val;
		sum[id]=(r-l+1)*val;
		return;
	}
	updata(id,l,r);
	int mid=(l+r)>>1;
	change(id<<1,l,mid,lx,rx,val);
	change(id<<1|1,mid+1,r,lx,rx,val);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}


int ask(int x)
{
	int ans=dep[x],tx;
	do
	{	
		tx=top[x];
		ans-=query(1,1,dfn,seg[tx],seg[x]);
		change(1,1,dfn,seg[tx],seg[x],1);
		x=father[tx];
	}while(tx!=x);
	return ans;
}

void work()
{
	char p[20];
	int x,ans;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d",p,&x);
		if(p[0]=='u')
		{
			ans=query(1,1,dfn,seg[x],end[x]);
			change(1,1,dfn,seg[x],end[x],0);
		}
		else ans=ask(x);
		printf("%d\n",ans);
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int a;
	memset(head,-1,sizeof(head));
	memset(tag,-1,sizeof(tag));
	for(int i=1;i<n;i++)
		scanf("%d",&a),build(a,i);
	make_part();
	work();
	return 0;
}