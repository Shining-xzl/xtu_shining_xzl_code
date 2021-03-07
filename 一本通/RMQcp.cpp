#include <cstdio>
using namespace std;

#define Max(x,y) (x)>(y)?(x):(y)
#define Min(x,y) (x)<(y)?(x):(y)

const int lim=5e4+4;

int min[lim][20];
int max[lim][20];
int n,m,log2[lim];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	log2[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&max[i][0]);
		min[i][0]=max[i][0];
		log2[i]=log2[i>>1]+1;
	}
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			max[j][i]=Max(max[j][i-1],max[j+(1<<i-1)][i-1]);
			min[j][i]=Min(min[j][i-1],min[j+(1<<i-1)][i-1]);
		}
	int l,r,p,MAX,MIN;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		p=log2[r-l+1];
		MAX=Max(max[l][p],max[r-(1<<p)+1][p]);
		MIN=Min(min[l][p],min[r-(1<<p)+1][p]);
		printf("%d\n",MAX-MIN);
	}
	return 0;
}