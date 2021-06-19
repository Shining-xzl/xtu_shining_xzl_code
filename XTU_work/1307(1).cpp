#include <cstdio>
using namespace std;
typedef long long ll;

int get(ll x)
{
	if (x < 0) return 0;
	if (x == 0) return 1;
	ll temp;
	int len = 62;
	while(((1ll << len) & x )== 0) --len;
	int res = 1 + len * (len - 1) / 2;
	temp = ((1ll << (len + 1)) - 1);
	for (int i = 0; i < len; ++i)
		if ((temp ^ (1ll << i) )<= x) ++res;
	return res;
}

int main()
{
	int T;
	ll a,b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &a,&b);
		printf("%d\n",get(b) - get(a-1));
	}
	return 0;
}