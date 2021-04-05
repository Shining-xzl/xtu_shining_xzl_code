#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 1e5+4;
int s[lim],n;

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
			scanf("%d",&s[i]);
		sort(s,s+n);
		int a,b;
		b = n/2;
		a = b-1;
		while(a >= 0 && b < n)
		{
			printf("%d %d ",s[b++],s[a--]);
		}
		if(b < n) printf("%d",s[b] );
		printf("\n");
	}
	return 0;
}