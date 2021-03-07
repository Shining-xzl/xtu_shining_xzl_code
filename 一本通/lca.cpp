#include <bits/stdc++.h>
using namespace std;

template <typename READ>
void read(READ &a)
{
	a=0;
	char c=getchar();
	bool flag=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=1;
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
	char c[20],len=0;
	if(a<0) putchar('-'),a=-a;
	do
	{
		c[len++]=a%10+48;
		a/=10;
	}while(a>0);
	while(len--) putchar(c[len]);
	putchar('\n');
} 
int n;
vector< vector<int> > son;
vector< vector<int> > fa;
vector< int > dep;

void dfs_build(int id,int father)
{
	dep[id]=dep[father]+1;
	fa[id][0]=father;
	for(int i=0;i<19;i++)
		fa[id][i+1]=fa[fa[id][i]][i];
	int v,len=son[id].size();
	for(int i=0;i<len;i++)
	{
		v=son[id][i];
		if(v==father) continue;
		dfs_build(v,id);
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
	for(int i=19;i>=0;i--)
		if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
	if(a==b) return a;
	for(int i=19;i>=0;i--)
	{
		if(fa[a][i]!=fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}

int main()
{
	// freopen("in.txt","r",stdin);
	read(n);
	son.resize(n+3,vector<int>(0) );
	fa.resize(n+3,vector<int>(20,0) );
	dep.resize(n+3,0);
	int a,b,m;
	for(int i=1;i<n;i++)
	{
		read(a);
		read(b);
		son[a].push_back(b);
		son[b].push_back(a);
	}
	dfs_build(1,0);
	read(m);
	while(m--)
	{
		read(a);
		read(b);
		write(dep[a]+dep[b]-2*dep[LCA(a,b)]);
	}
	return 0;
}
