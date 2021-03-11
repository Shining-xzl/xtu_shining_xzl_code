#include <bits/stdc++.h>
using namespace std;
const int limN=2e6+3;
const int limK=1e4+3;

int p[limN],c[limN];
int sum[limK],cnt[limK],la[limK];
int N,P,K;
long long ans;

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&N,&K,&P);
	for(int i=1;i<=N;i++)
		scanf("%d%d",&c[i],&p[i]);
	int now=0;
	for(int i=1;i<=N;i++)
	{
		if(p[i]<=P) now=i;
		if(la[c[i]]<=now) sum[c[i]]=cnt[c[i]];
		la[c[i]]=i;
		cnt[c[i]]++;
		ans+=sum[c[i]];
	}
	printf("%lld\n",ans);
	return 0;
}