#include <cstdio>

using namespace std;
#define Min(x,y) ((x)<(y)?(x):(y))
#define Max(x,y) ((x)>(y)?(x):(y))
typedef long long ll; 
const int lim = 2e5+3;

ll abs(ll x)
{
	if(x>0) return x;
	else return -x;
}

ll sum[lim];
int n;

ll solve(int p1,int p2,int p3)
{
	ll MIN,MAX;
	MIN = Min(sum[p1],sum[p2]-sum[p1]);
	MIN = Min(MIN,sum[p3]-sum[p2]);
	MIN = Min(MIN,sum[n]-sum[p3]);
	MAX = Max(sum[p1],sum[p2]-sum[p1]);
	MAX = Max(MAX,sum[p3]-sum[p2]);
	MAX = Max(MAX,sum[n]-sum[p3]);
	return MAX - MIN;
}

bool offset(int head,int pos,int tag)
{
	ll pre = abs((sum[pos]-sum[head]) - (sum[tag]-sum[pos]));
	++pos;
	ll now = abs((sum[pos]-sum[head]) - (sum[tag]-sum[pos]));
	return now < pre;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i-1];
	}
	ll ans = 1e18,temp;
	int p1 = 1,p2,p3 = 3;
	for (p2 = 2; p2 < n; ++p2)
	{
		while(offset(0,p1,p2)) ++p1;
		while(offset(p2,p3,n)) ++p3;
		temp = solve(p1,p2,p3);
		ans = Min(ans,temp);
	}
	printf("%lld\n", ans);
	return 0;
}
