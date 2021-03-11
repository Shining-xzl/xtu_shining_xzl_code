#include <cstdio>
#include <vector>
using namespace std;

#define Min(x,y) ((x)<(y)?(x):(y))

const int limN=2e6+3;
const int limK=1e4+3;
typedef long long LL;

int c[limN];
char log2[limN];
vector< vector<char> > p;
int N,K,P;
bool vis[limK];
vector< vector<int> > k;
vector<int> posk;

bool get_Min(int l,int r)
{
	int len=log2[r-l+1];
	return Min(p[l][len],p[r-(1<<len)+1][len])<=(char)P;
}

LL get_ans(int c)
{
	int l=posk[c]+1,r=k[c].size()-1,mid;
	if(l>r||vis[c]) return 0LL;
	if(!get_Min(k[c][posk[c]],k[c][r]))
	{
		vis[c]=1;
		return 0LL;
	}
	while(l<r)
	{
		mid=(l+r)>>1;
		if(get_Min(k[c][posk[c]],k[c][mid])) r=mid;
		else l=mid+1;
	}
	LL ans=k[c].size()-l;
	posk[c]++;
	return ans;
}

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

int main()
{
	scanf("%d%d%d",&N,&K,&P);
	k.resize(K+5,vector<int>(0) );
	posk.resize(K+5,0);
	p.resize(N+3,vector<char>(27,0) );
	int x;
	log2[0]=-1;
	for(int i=1;i<=N;i++)
	{
		// scanf("%d%d",&c[i],&x);
		read(c[i]);
		read(x);
		p[i][0]=x;
		k[c[i]].push_back(i);
		log2[i]=log2[i>>1]+1;
	}
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j+(1<<i)-1<=N;j++)
			p[j][i]=Min(p[j][i-1],p[j+(1<<i-1)][i-1]);
	LL ans=0ll;
	for(int i=1;i<N;i++)
	{
		ans+=get_ans(c[i]);
	}
	// printf("%lld\n",ans);
	write(ans);
	return 0;
}
