#include <cstdio>

using namespace std;
const int lim = 10003;
int n;
int a[lim],k[lim];
int ans;

int read()
{
	int res = 0;
	char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = (res << 3) + (res << 1) + (c ^ 48);
		c = getchar();
	}
	return res;
}

void sort_gb(int l,int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	sort_gb(l,mid); sort_gb(mid+1,r);
	int i = l, j = mid + 1, p = l;
	while(i <= mid || j <= r)
	{
		if (i > mid) k[p++] = a[j++];
		else if (j > r) k[p++] = a[i++], ans += r - mid;
		else
		{
			if (a[i] <= a[j]) k[p++] = a[i++], ans += j - mid - 1;
			else k[p++] = a[j++];
		}
	}
	for (p = l; p <= r; ++p)
		a[p] = k[p];
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		if (n == 0) break;
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		ans = 0;
		sort_gb(1,n);
		printf("%d\n",ans);
	}
	return 0;
}