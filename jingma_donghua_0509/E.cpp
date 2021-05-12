#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int lim = 1<<18;
int n,m;
int s[lim+3];
LL ans[20];
LL stand[20];
int temp[lim+3];

void sort_gb(int l,int r,int id)
{
	if(l == r) return;
	int mid = (l + r) >> 1;
	sort_gb(l,mid,id-1);
	sort_gb(mid+1,r,id-1);
	int a = l,b = mid + 1, op = l;
	while(a <= mid || b <= r)
	{
		if(b > r) temp[op++] = s[a++], ans[id] += (LL)(r - mid);
		else if(a > mid) temp[op++] = s[b++];
		else
		{
			if(s[a] <= s[b]) temp[op++] = s[a++], ans[id] += (LL)(b - mid - 1);
			else temp[op++] = s[b++];
		}
	}
	for (int i = l; i <= r; ++i)
		s[i] = temp[i];
}

void process()
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; ++i)
		stand[i] = (1LL << i-1) * (1LL << i-1) * (1LL << n-i);
	sort_gb(1,1<<n,n);
	int x;
	LL res = 0;
	for (int i = 1; i <= n; ++i)
		res += ans[i];
	while(m--)
	{
		scanf("%d", &x);
		for (int i = 1; i <= x; ++i)
		{
			res -= ans[i] * 2 - stand[i];
			ans[i] = stand[i] - ans[i];
		}
		printf("%lld\n", res);
	}
}

int main()
{
	while(scanf("%d %d",&n,&m) == 2)
	{
		for (int i = 0; i < (1<<n); ++i)
			scanf("%d", s+i+1);
		process();
	}
	return 0;
}