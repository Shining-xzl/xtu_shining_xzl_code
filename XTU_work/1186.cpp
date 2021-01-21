#include <cstdio>
#include <cstring>

using namespace std;
const int MAX=1e+9;
int d[12][12];
int n,ans,path[103],len;
bool is[12];

void dfs(int k,int p,int l,int s)
{
	if(l>ans) return;
	if(k==n)
	{
		l+=d[s][0];
		if(l<ans)
		{
			len=0;
			ans=l;
			path[++len]=p;
		}
		else if(l==ans&&len<10) path[++len]=p;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!is[i])
		{
			is[i]=1;
			dfs(k+1,(p<<3)+(p<<1)+i,l+d[s][i],i);
			is[i]=0;
		}
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,i,j;
	int num[12],l;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				scanf("%d",&d[i][j]);
		ans=MAX;
		dfs(0,0,0,0);
		printf("%d\n",ans);
		for(i=1;i<=len;i++)
		{
			l=0;
			while(path[i]>0)
			{
				num[++l]=path[i]%10;
				path[i]/=10;
			}
			for(j=l;j>1;j--)
				printf("%d ",num[j]);
			printf("%d\n",num[1]);
		}
	}
	return 0;
}

