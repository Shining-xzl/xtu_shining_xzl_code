#include <cstdio>
#include <algorithm>
using namespace std;
int s[80];
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n*2; ++i)
			scanf("%d", &s[i]);
		sort(s,s+n+n);
		int t;
		for (int i = 0; i < n*2; i += 2)
		{
			t = s[i];
			s[i] = s[i+1];
			s[i+1] = t;
		}
		t = s[0];
		s[0] = s[n*2-1];
		s[n*2-1] = t;
		for (int i = 0; i < n*2; ++i)
		{
			printf("%d ",s[i]);
		}
		printf("\n");
	}
	return 0;
}