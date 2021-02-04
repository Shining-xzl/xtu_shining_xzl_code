#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int LIM=1e5+5;
int n;
LL k;
LL s[LIM];

bool check(LL x)
{
	LL num=k;
	LL dis;
	for(int i=1;i<n;i++)
	{
		dis=s[i]-s[i-1];
		if(dis<=x) continue;
		if(dis%x==0)  num-=(dis/x-1);
		else num-=(dis/x);
		if(num<0) return 0;
	}
	return 1;
}

LL get_ans()
{
	LL l=1,r=1e12,mid,ans=1e12;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		} 
		else l=mid+1;
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lld",&s[i]);
	sort(s,s+n);
	printf("%lld\n",get_ans());
	return 0;
 } 
