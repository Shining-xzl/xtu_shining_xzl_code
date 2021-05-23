#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int lim = 1e6+3;
LL s[lim];
LL sum,M;
int n;

#define Abs(x) ((x)>0?(x):-(x))

int main()
{
	// freopen("in.txt","r",stdin);
	while(scanf("%d", &n) == 1 && n)
	{
		sum = 0LL;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &s[i]);
			sum += s[i];
		}
		M = sum / (LL)n;
		for (int i = 0; i < n; ++i)
		{
			s[i] -= M;
			if(i) s[i] += s[i-1];
		}
		s[n-1] = 0LL;
		sort(s,s+n);
		sum = 0LL;
		for (int i = 0; i < n; ++i)
			sum += Abs(s[i]-s[n/2]);
		printf("%lld\n", sum);
	}
	return 0;
}