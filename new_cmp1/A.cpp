#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 1e5+3;
int s[lim];

int main()
{
	int n,h,m;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&h,&m);
		s[i] = h*60 + m;
	}
	sort(s,s+n);
	int ans = 1, temp = 1;
	for (int i = 1; i < n; ++i)
	{
		if(s[i] == s[i-1])
			temp++;
		else temp = 1;
		if(temp > ans)
			ans = temp;
	}
	printf("%d\n", ans);
	return 0;
}