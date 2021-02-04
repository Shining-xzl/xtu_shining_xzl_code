#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD=998244353;

LL kkk(LL x)
{
	if(x==0) return 1LL;
	LL res=kkk(x/2);
	res=res*res%MOD;
	if(x&1)
	{
		res=res*2%MOD; 
	}
	return res;
}

LL get(LL n,int m)
{
	if(m==0)
	{
		if(n<2) return n+1;
		else return n+2;
	}
	else if(m==1)
	{
		if(n<2) return n+1;
		else return n*2;
	}
	else return kkk(n);
}

int main()
{
//	freopen("in.txt","w",stdout);
	int time,m;
	LL n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%lld%d",&n,&m);
		printf("%lld\n",get(n,m)%MOD);
	}
	return 0;
 } 
