#include <cstdio>

using namespace std;
const int lim = 1e5+4;

int a[lim];

int main()
{
	int n,m,x,op;
	while(scanf("%d %d", &n,&m) == 2)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		op = 0;
		while(m--)
		{
			scanf("%d", &x);
			op += x - 1;
			op %= n;
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ",a[op]);
			op++;
			op %= n;
		}
		printf("\n");
	}
	return 0;
}