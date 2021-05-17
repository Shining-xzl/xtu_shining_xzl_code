/*
找钝角直角三角形，逆时针结合计数
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 2e4+3;
const double eps = 1e-6;
double s[lim<<1];
typedef long long LL;
LL res = 0LL,n;

LL solve()
{
	LL res = n * (n-1) * (n-2) / 6,len;
	int pos;
	double opo;
	for (LL i = 0; i < n; ++i)
	{
		opo = s[i] + 180.0 + eps;
		pos = lower_bound(s,s+n*2,opo) - s;
		if(s[pos] > opo) --pos;
		len = pos - i;
		res -= len * (len - 1) / 2;
	}
	return res;
}

int main()
{
	int Case = 0;
	while(scanf("%lld%*d",&n) != EOF && n)
	{
		for (int i = 0; i < n; ++i)
			scanf("%lf", &s[i]);
		sort(s,s+n);
		for (int i = 0; i < n; ++i)
			s[i+n] = s[i] + 360.0;
		printf("Case %d: %lld\n", ++Case,solve());
	}
	return 0;
} 
