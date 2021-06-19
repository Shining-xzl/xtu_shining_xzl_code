#include <cstdio>
using namespace std;
int a[10003];
int n,m;

bool check(int x)
{
	int count = 1, t = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > x) return 0;
		t += a[i];
		if (t > x)
		{
			++count;
			t = a[i];
		}
	}
	return count <= m;
}

int solve()
{
	int l = 0, r = 1e9;
	int mid,ans = r;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n,&m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		printf("%d\n",solve());
	}
	return 0;
} 
