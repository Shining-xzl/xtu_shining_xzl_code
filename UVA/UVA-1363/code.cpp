#include <cstdio>
using namespace std;
typedef long long LL;

LL find_by(LL l, LL r,LL p,LL k)
{
	LL mid,ans = l;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(k / mid == p)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

LL solve(LL n,LL k) // 利用商相等的等差
{
	LL res = 0;
	LL l = 1, p,num,remainder,end;
	while(l <= n)
	{
		p = k / l;
		remainder = k % l;
		if(p == 0) break;
		end = find_by(l,n,p,k);
		num = end - l;
		res += (remainder * 2 - num * p) * (num + 1) / 2;
		l = end + 1;
	}
	if (l <= n)
		res += (n - l + 1) * k;
	return res;
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	LL n,k;
	while(scanf("%lld %lld", &n, &k) == 2)
		printf("%lld\n",solve(n,k));
	return 0;
} 
