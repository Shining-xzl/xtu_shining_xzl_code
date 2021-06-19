#include <cstdio>
using namespace std;

typedef long long ll;
const int lim = 1003;
ll a[lim],b[lim],k;
int n;

bool check(int x)
{
	ll t = k;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] * x <= b[i]) continue;
		else t -= a[i] * x - b[i];
		if (t < 0) return 0;
	}
	return 1;
}

int main()
{
	int T;
	ll l,r,mid,ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %lld", &n,&k);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &b[i]);
		l = 0; r = 2e9;
		ans = 0;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if (check(mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else r= mid - 1;
		}
		printf("%lld\n",ans);
	}	
	return 0;
} 
