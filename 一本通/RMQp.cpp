#include <cstdio>
using namespace std;

#define Max(x,y) (x)>(y)?(x):(y)

const int lim=2e5+4;

int ans[lim][20];
int n,m;
int log2[lim];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	log2[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ans[i][0]);
		log2[i]=log2[i>>1]+1;
	}
	for(int i=1;i<20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			ans[j][i]=Max(ans[j][i-1],ans[j+(1<<i-1)][i-1]);
	scanf("%d",&m);
	int l,r,p;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		p=log2[r-l+1];
		printf("%d\n",Max(ans[l][p],ans[r-(1<<p)+1][p]));
	}
	return 0;
}