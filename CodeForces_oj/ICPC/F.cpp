#include <bits/stdc++.h>
using namespace std;
int n,k,p;
long long sum = 0;
int ans[100003];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d %d %d",&n,&k,&p);
	for (int i = 1; i <= n-k; ++i)
		ans[i] = 1;
	int pre = 0;
	for (int i = n-k+1; i <= n; ++i)
	{
		if(pre * 100 < (i-1) * p) 
		{
			ans[i] = ans[i-1] + 1;
			pre = i - 1;
		} 
		else ans[i] = ans[i-1];
	}
	for (int i = 1; i <= n; ++i)
		sum = sum + (long long) ans[i];
	printf("%lld\n", sum);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}