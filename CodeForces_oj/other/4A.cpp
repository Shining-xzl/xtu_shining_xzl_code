#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i+=2)
	{
		if(!((n-i)&1))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
