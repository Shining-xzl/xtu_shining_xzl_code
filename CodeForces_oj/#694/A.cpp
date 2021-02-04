#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum,Min,Max;
int n,x;
int main()
{
//	freopen("in.txt","r",stdin);
	int time,temp;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&x);
		sum=0;
		Min=Max=0;
		while(n--)
		{
			scanf("%d",&temp);
			Max+=(LL)temp/x;
			sum+=(LL)temp;
			if(temp%x!=0) Max++;
		}
		Min=(LL)sum/x;
		if(sum%x!=0) Min++;
		printf("%lld %lld\n",Min,Max);
	}
	return 0;
}