/*
离散化加乘法逆元
前缀和
组合数学
算法思维
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int LIM=200003;
const long long MOD=1e9+7;
int num[LIM],sum[LIM];
int q[LIM],n,m,k,len;
long long inv[LIM],C[LIM];

void prime()//处理组合数，乘法逆元
{
	C[1]=1;
	for(int i=2;i<=200000;i++)
		C[i]=i*C[i-1]%MOD;//分子
	inv[0]=1;
	inv[1]=1;
	for(int i=2;i<=200000;i++)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;//分母
	for(int i=2;i<=200000;i++)
		inv[i]=inv[i]*inv[i-1]%MOD;//分母相乘
}

long long get_C(int n,int m)//组合数公式快速算
{
	if(m>n) return 0;
	if(n==0) return 1;
	long long ans;
	ans=(C[n]*inv[m]%MOD)*inv[n-m]%MOD;
	return ans;
}

void intiail()
{
	scanf("%d%d%d",&n,&m,&k);
	len=0;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(num[x]==0)
			q[++len]=x;
		num[x]++;
	}
	int l=1;
	sort(q+1,q+len+1);
	for(int i=1;i<=len;i++)
	{
		x=q[i];
		y=q[i-1];
		num[x]+=num[y];//前缀和
		while(x-q[l]>k) l++;
		sum[i]=num[x]-num[q[l-1]];//有效前缀和
	}
	long long ans=0,a,b;
	for(int i=1;i<=len;i++)
	{
		x=q[i];
		y=q[i-1];
		a=num[x]-num[y];
		b=sum[i]-a;
		for(int i=1;i<=m;i++)//已当前的数为标准，乘法原理求当前贡献
		{
			ans+=get_C(a,i)*get_C(b,m-i)%MOD;
			ans%=MOD;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		num[q[i]]=0;
}

int main()
{
	prime();
	int time;
	scanf("%d",&time);
	while(time--)
	{
		intiail();
	}
	return 0;
}