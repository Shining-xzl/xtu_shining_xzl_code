#include <cstdio>
using namespace std;
const int lim = 1e5+3;
typedef long long LL;
LL N,A,B;
LL h[lim];

bool check(LL x)
{
	LL ans = 0,temp;
	for (int i = 0; i < N; ++i)
	{
		temp = h[i] - x * B;
		if(temp > 0)
		{
			ans += temp/A;
			if(temp%A > 0) ++ans;
		}
	}
	return ans <= x;
}

int main()
{
	LL Max = 0;
	scanf("%lld %lld %lld", &N,&A,&B);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &h[i]);
		Max = Max < h[i] ? h[i] : Max;
	}	
	A -= B;
	LL mid,l=0,r = Max/B + 1; 
	while(l < r)
	{
		mid = (l+r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", r);
	return 0;
}