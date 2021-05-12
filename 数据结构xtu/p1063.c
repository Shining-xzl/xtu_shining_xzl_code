#include <stdio.h>

int s[30003],q[30003];
int ans,n;

void sort(int l,int r)
{
	if(l == r) return;
	int a = l, b = r, t, mid = (s[l] + s[r])/2;
	while(a <= b)
	{
		while(s[a] < mid) a++;
		while(s[b] > mid) b--;
		if(a <= b)
		{
			t = s[a];
			s[a] = s[b];
			s[b] = t;
			a++;
			b--;
		}
	}
	if(a < r) sort(a,r);
	if(b > l) sort(l,b);
}

int main()
{
	scanf("%d",&n);
	int i, op = 0, l = 0, r = -1,a,b;
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);
	sort(0,n-1);

	ans = 0;
	for (i = 1; i < n; ++i)
	{
		if(op < n && l <= r)
		{
			if(s[op] < q[l]) a = s[op++];
			else a = q[l++];
		}
		else if(op < n) a = s[op++];
		else a = q[l++];

		if(op < n && l <= r)
		{
			if(s[op] < q[l]) b = s[op++];
			else b = q[l++];
		}
		else if(op < n) b = s[op++];
		else b = q[l++];
		q[++r] = a + b;
		ans += a + b;
	}
	printf("%d\n", ans);
	return 0;
}