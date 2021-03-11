#include <cstdio>
using namespace std;

#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

const int lim=1e5+3;
int log2[lim];
int n,k;
int Max[lim][20],Min[lim][20];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	log2[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&Max[i][0]);
		Min[i][0]=Max[i][0];
		log2[i]=log2[i>>1]+1;
	}
	for(int i=1;i<20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			Min[j][i]=min(Min[j][i-1],Min[j+(1<<(i-1))][i-1]);
			Max[j][i]=max(Max[j][i-1],Max[j+(1<<(i-1))][i-1]);
		}
	int p=log2[k];
	for(int i=1;i+k-1<=n;i++)
	{
		printf("%d ",max(Max[i][p],Max[i+k-(1<<p)][p]));
		printf("%d\n",min(Min[i][p],Min[i+k-(1<<p)][p]));
	}
	return 0;
}