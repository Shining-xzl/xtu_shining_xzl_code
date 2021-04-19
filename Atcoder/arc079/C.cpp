#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL s[56];
LL n;
LL k,add,ans = 0,temp;

#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &s[i]);
	sort(s,s+n);
	k = s[0];
	for (int i = 1; i < n; ++i)
	{
		s[i] -= s[0];
		k += s[i]/(n+1);
		ans += s[i]/(n+1);
		s[i] %= (n+1);
	}
	s[0] = 0;
	sort(s,s+n);
	if(n - s[n-1] <= k)
	{
		add = n - s[n-1];
		k -= add;
		temp = k * n + n;
		for (int i = 0; i < n; ++i)
			s[i] += add;
		LL tk,ta;
		for (int i = 0; i < n - 1; ++i)
		{
			ta = n - i - 1;
			tk = k + ta;
			tk -= (n - 1 - s[i]);
			if(tk < 0) tk = 0;
			ta += tk * n;
			temp = Min(ta,temp);
		}
		ans += temp;
	}
	printf("%lld\n", ans);
	return 0;
}