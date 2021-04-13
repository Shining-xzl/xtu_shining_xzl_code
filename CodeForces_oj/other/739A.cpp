#include <cstdio>

using namespace std;
int main()
{
	int n,m,l,r,Min = 1e9;
	scanf("%d %d", &n,&m);
	while(m--)
	{
		scanf("%d %d",&l,&r);
		if(r-l+1 < Min)
			Min = r - l + 1;
	}
	printf("%d\n", Min);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", i%Min);
	}
	return 0;
}