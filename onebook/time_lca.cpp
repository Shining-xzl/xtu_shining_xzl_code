#include <cstdio>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;

const int lim=1e5+3;

struct node
{
	int son,next,w;
}edge[lim<<1];

typedef long long LL;
int head[lim],dep[lim],f[lim][22],dfn[lim];
LL len[lim],ans;
int logN,op=0,N,M,dfN=0;

class cmp
{
public:
	bool operator () (const int &a,const int &b)
	{
		return dfn[a]<dfn[b];
	}
};

/*
struct cmp
{
	bool operator () (const int &a,const int &b)
	{
		return dfn[a]<dfn[b];
	}
};
*/

set<int,cmp> library;

void build(int a,int b,int w)
{
	op++;
	edge[op].son=a;
	edge[op].w=w;
	edge[op].next=head[b];
	head[b]=op;
	op++;
	edge[op].son=b;
	edge[op].w=w;
	edge[op].next=head[a];
	head[a]=op;
}

void initail()
{
	scanf("%d",&N);
	memset(head,-1,sizeof(head));
	logN=log2(N)+1;
	int a,b,w;
	for(int i=1;i<N;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		build(a,b,w);
	}
}

void make_tree(int now,int fa)
{
	f[now][0]=fa;
	dep[now]=dep[fa]+1;
	dfn[now]=(++dfN);
	for(int i=0;i<logN;i++)
		f[now][i+1]=f[f[now][i]][i];
	for(int i=head[now],v;i!=-1;i=edge[i].next)
	{
		v=edge[i].son;
		if(v==fa) continue;
		len[v]=len[now]+edge[i].w;
		make_tree(v,now);
	}
}


int LCA(int a,int b)
{
	int x;
	if(dep[a]<dep[b]) x=a,a=b,b=x;
	for(int i=logN;i>=0;i--)
		if(dep[f[a][i]]>=dep[b])
			a=f[a][i];
	if(a==b) return a;
	for(int i=logN;i>=0;i--)
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	return f[a][0];
}


typedef set<int,cmp>::iterator It;

LL process(It &now)
{
	It R,L;
	if(now==library.begin())
	{
		R=now;R++;
		L=--(library.end());
	}
	else if(now==(--library.end()))
	{
		R=library.begin();
		L=now;L--;
	}
	else
	{
		R=L=now;
		R++;L--;
	}
	int a=*R,b=*L,x=*now;
	LL temp;
	int father;
	father=LCA(a,x);
	temp=len[a]+len[x]-(len[father]<<1);
	father=LCA(b,x);
	temp+=len[b]+len[x]-(len[father]<<1);
	father=LCA(a,b);
	temp-=len[a]+len[b]-(len[father]<<1);
	return temp;
}

void Insert(int x)
{
	pair<It,bool> p;
	p=library.insert(x);
	It now;
	now=p.first;
	if(library.size()<=1) return;
	ans+=process(now);
}

void Erase(int x)
{
	It now;
	now=library.find(x);
	if(library.size()<=1)
	{
		library.erase(x);
		return;
	}
	ans-=process(now);
	library.erase(x);
}

void work()
{
	scanf("%d",&M);
	char c;
	int x;
	while(M--)
	{
		scanf(" %c",&c);
		if(c=='?')
		{
			printf("%lld\n",ans>>1);
		}	
		else
		{
			scanf("%d",&x);
			if(c=='+') Insert(x);
			else Erase(x);
		}
		// printf("%c\n",c);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	initail();
	make_tree(1,0);
	work();
	return 0;
}