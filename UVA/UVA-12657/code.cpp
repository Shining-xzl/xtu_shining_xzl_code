#include <cstdio>
using namespace std;
const int lim=1e5+3;
int linkr[lim];
int linkl[lim];
int n,m,Case=0;
int *L,*R;

template<typename SWAP>
void swap(SWAP &a,SWAP &b)
{
	SWAP x=a;a=b;b=x;
}

void initial()
{
	for(int i=0;i<=n+1;i++)
	{
		linkl[i]=i-1;
		linkr[i]=i+1;
	}
	L=linkl;
	R=linkr;
}

void work()
{
	int p,x=0,y=0,o=0;
	while(m--)
	{
		scanf("%d",&p);
		if(p!=4) scanf("%d%d",&x,&y);
		else swap(L,R),o^=1;
		int a,b,c,d;
		a=L[y]; b=R[y];
		c=L[x]; d=R[x];
		switch(p)
		{
			case 1:
				if(L[y]!=x)
				{
					R[c]=d; L[d]=c;
					R[a]=x; L[y]=x;
					L[x]=a; R[x]=y;
				}
				break;
			case 2:
				if(R[y]!=x)
				{
					R[c]=d; L[d]=c;
					L[b]=x; R[y]=x;
					L[x]=y; R[x]=b;
				}
				break;
			case 3:
				if(R[y]==x)
				{
					R[a]=x; L[d]=y;
					L[x]=a; R[y]=d;
					R[x]=y; L[y]=x;
				}
				else if(L[y]==x)
				{
					R[c]=y; L[b]=x;
					R[x]=b; L[y]=c;
					L[x]=y; R[y]=x;
				}
				else
				{
					R[a]=x; L[x]=a; L[b]=x; R[x]=b;
					R[c]=y; L[y]=c; L[d]=y; R[y]=d;
				}
				break;
			default: break;
		}
	}
	unsigned int ans=0,now;
	if(o) now=linkl[n+1];
	else now=linkr[0];
	for(int i=1;i<=n;i++)
	{
		if(i&1) ans+=now;
		if(o) now=linkl[now];
		else now=linkr[now];
	}
	printf("Case %d: %u\n",++Case,ans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)==2)
	{
		initial();
		work();
	}
	return 0;
} 
