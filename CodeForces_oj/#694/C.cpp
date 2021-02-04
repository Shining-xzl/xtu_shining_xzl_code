#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int LIM=3e5+3;
LL ans;
int k[LIM],c[LIM];
int n,m;

int main()
{
//	freopen("in.txt","r",stdin);
	int time,op;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&k[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&c[i]);	
		sort(k+1,k+n+1);
		op=1;
		ans=0;
		for(int i=n;i>0;i--)
		{
			if(op<=k[i]) ans+=c[op++];
			else ans+=c[k[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}