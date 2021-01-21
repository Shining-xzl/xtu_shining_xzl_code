#include <cstdio>
using namespace std;
const int TNT=1000000;
const int MOD=1000000007;
int ans[TNT+2];

void prime()
{
	int i,k;
	int f[3],a,b,c;
	ans[1]=0;
	ans[2]=1;
	ans[3]=3;
	a=2;
	b=1;
	c=0;
	f[b]=5;
	f[c]=3;
	k=1<<3;
	for(i=4;i<=TNT;i++)
	{
		f[a]=f[b]+f[c];
		if(f[a]>=MOD) f[a]-=MOD;
		k<<=1;
		if(k>=MOD) k-=MOD;
		ans[i]=k-f[a];
		if(ans[i]<0) ans[i]+=MOD;
		a++;
		b++;
		c++;
		if(a>2) a-=3;
		else if(b>2) b-=3;
		else if(c>2) c-=3;
	}
}

int main()
{
	prime();
	int time,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
