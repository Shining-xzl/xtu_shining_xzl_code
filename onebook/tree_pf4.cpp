#include <cstdio>
#include <cstring>
using namespace std;

const int lim=1e5+3;
int son[lim],size[lim],top[lim],dep[lim],seg[lim],rev[lim],father[lim];
int n,m,head[lim],op=0,col[lim];
struct edge
{
	int son,next;
}s[lim<<1];
#define sgl seg[0]

struct tree
{
	int L,R,Num;
	int colL,colR,tag; 	
}p[lim<<2];

void build(int a,int b)
{
	op++;
	s[op].son=b;
	s[op].next=head[a];
	head[a]=op;
}

void initail()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&col[i]);
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		build(a,b);build(b,a);
	}
}

void dfs1(int now)
{
	dep[now]=dep[father[now]]+1;
	size[now]=1;
	for(int i=head[now],v;v=s[i].son,i!=-1;i=s[i].next)
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
	for(int i=head[now];i!=-1,v=s[i].son;i=s[i].next)
		if(!top[v])
		{
			seg[v]=++sgl;
			rev[sgl]=v;
			top[v]=v;
			dfs2(v);
		}
}

void make_part()
{
	dfs1(1);
	seg[1]=top[1]=rev[1]=sgl=1;
	dfs2(1);
}

void down(int id)
{
	int L=id<<1,R=id<<1|1;
	if(p[id].tag==-1) return;
	p[L].Num=p[R].Num=1;
	p[L].tag=p[R].tag=p[id].tag;
	p[L].colL=p[L].colR=p[id].tag;
	p[R].colL=p[R].colR=p[id].tag;
	p[id].tag=-1;
}

void updata(int id)
{
	p[id].Num=p[id<<1].Num+p[id<<1|1].Num;
	p[id].colL=p[id<<1].colL;
	p[id].colR=p[id<<1|1].colR;
	if(p[id<<1].colR==p[id<<1|1].colL) 
		p[id].Num--;
}

void make_tree(int id,int l,int r)
{
	p[id].L=l;
	p[id].R=r;
	p[id].tag=-1;
	if(l==r)
	{
		p[id].colL=p[id].colR=col[rev[l]];
		p[id].Num=1;
		return;
	}
	int mid=l+r>>1;
	make_tree(id<<1,l,mid);
	make_tree(id<<1|1,mid+1,r);
	updata(id);
}

void change(int id,int l,int r,int val)
{
	if(p[id].L>r||p[id].R<l) return;
	if(p[id].L>=l&&p[id].R<=r)
	{
		p[id].colL=p[id].colR=val;
		p[id].Num=1;
		p[id].tag=val;
		return;
	}
	down(id);
	change(id<<1,l,r,val);
	change(id<<1|1,l,r,val);
	updata(id);
}

int lc,rc;
int query(int id,int l,int r)
{
	if(p[id].L>r||p[id].R<l) return 0;
	if(p[id].L>=l&&p[id].R<=r) 
	{
		
		if(l==p[id].L) lc=p[id].colL;
		if(r==p[id].R) rc=p[id].colR;
		return p[id].Num;
	}
	down(id);
	int mid=(p[id].L+p[id].R)>>1,ans;
	if(mid<l) return query(id<<1|1,l,r);
	else if(mid>=r) return query(id<<1,l,r);
	ans=query(id<<1|1,l,r)+query(id<<1,l,r);
	if(p[id<<1].colR==p[id<<1|1].colL) ans--;
	return ans;
}

void swap(int &a,int &b)
{
	int x=a;a=b;b=x;
}

void ask(int a,int b,int c)
{
	int ta=top[a],tb=top[b];
	int ans=0,ca=-1,cb=-1;
	while(ta!=tb)
	{
		if(dep[ta]<dep[tb])
		{
			swap(a,b);
			swap(ta,tb);
			swap(ca,cb);
		}
		if(c!=-1) change(1,seg[ta],seg[a],c);
		else 
		{
			ans+=query(1,seg[ta],seg[a]);
			if(rc==ca) ans--;
			ca=lc;
		}
		a=father[ta];
		ta=top[a];
	}
	if(dep[a]>dep[b]) swap(a,b),swap(ca,cb);
	if(c!=-1) change(1,seg[a],seg[b],c);
	else 
	{
		ans+=query(1,seg[a],seg[b]);
		if(rc==cb) ans--;
		if(lc==ca) ans--;
		printf("%d\n",ans);
	}
}

void work()
{
	char Q;
	int a,b,c;
	while(m--)
	{
		scanf(" %c %d%d",&Q,&a,&b);
		if(Q=='C') scanf("%d",&c);
		else c=-1;
		ask(a,b,c);
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	initail();
	make_part();
	make_tree(1,1,sgl);
	work();
	return 0;
}