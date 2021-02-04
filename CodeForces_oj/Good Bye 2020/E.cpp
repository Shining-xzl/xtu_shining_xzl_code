#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL Mod=1e9+7;
const int T=5e5+3;
const LL o=1;
LL s[T];
LL sum;
LL jsum[T];
LL num[65];
int n;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
			for(int j=0;j<=60;j++)
				if(s[i]&(o<<j))
					num[j]++;
		}
		for(int i=1;i<=n;i++)
		{
			jsum[i]=0;
			for(int j=0;j<=60;j++)
				if(s[i]&(o<<j))
				{
					jsum[i]+=(o<<j)%Mod*n%Mod;
					jsum[i]%=Mod;
				}
				else
				{
					jsum[i]+=(o<<j)%Mod*num[j]%Mod;
					jsum[i]%=Mod;
				}
		}
		sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=60;j++)
				if(s[i]&(o<<j))
				{
					sum+=(o<<j)%Mod*num[j]%Mod*jsum[i]%Mod;
					sum%=Mod;
				}
		}
		printf("%lld\n",sum);
	}
	return 0;
}