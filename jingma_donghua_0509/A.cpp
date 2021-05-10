#include <cstdio>

using namespace std;
typedef long long LL;


int main()
{
	LL k,m;
	while(scanf("%lld %lld", &k,&m) == 2)
	{
		LL l,r,mid,ans;
		if (m <= k*(k+1)/2)
		{
			l = 0; r = k;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(mid*(mid+1)/2 < m)
				{
					ans = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			ans = ans + 2;
		}
		else
		{
			m = k * k - m + 1;
			l = 0; r = k;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(mid*(mid+1)/2 < m)
				{
					ans = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			ans = k + k - ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}