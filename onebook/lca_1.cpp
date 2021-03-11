#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N,M,S,NK;

vector< vector<int> > son,father;
vector< int > dep;

void initail()
{
	int a,b;
	scanf("%d%d%d",&N,&M,&S);
	son.resize(N+3,vector<int>(0) );
	dep.resize(N+3,0);
	for(int i=2;i<=N;i++)
	{
		scanf("%d%d",&a,&b);
		son[a].push_back(b);
		son[b].push_back(a);
	}
	NK=log2(N)+1;
	father.resize(N+3,vector<int>(NK+2) );
	
}

void build(int now,int fa)
{
	dep[now]=dep[fa]+1;
	father[now][0]=fa;
	for(int i=0;i<NK;i++)
	{
		father[now][i+1]=father[father[now][i]][i];
	}
	int len=son[now].size(),v;
	for(int i=0;i<len;i++)
	{
		v=son[now][i];
		if(v==fa) continue;
		build(v,now);
	}
}

int query(int a,int b)
{
	int x;
	if(dep[a]<dep[b]){x=a;a=b;b=x;}
	for(int i=NK;i>=0;i--)
		if(dep[father[a][i]]>=dep[b])
			a=father[a][i];
	if(a==b) return a;
	for(int i=NK;i>=0;i--)
	{
		if(father[a][i]!=father[b][i])
		{
			a=father[a][i];
			b=father[b][i];
		}
	}
	return father[a][0];
}

void work()
{
	int a,b,ans;
	while(M--)
	{
		scanf("%d%d",&a,&b);
		ans=query(a,b);
		printf("%d\n",ans);
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	initail();
	build(S,0);
	work();
	return 0;
}