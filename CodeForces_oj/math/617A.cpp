#include <cstdio>

using namespace std;

int main()
{
	int stand[] = {5,4,3,2,1};
	int x,ans = 0, i = 0;
	scanf("%d",&x);
	while(x > 0)
	{
		ans += x/stand[i];
		x %= stand[i++];
	}
	printf("%d\n", ans);
	return 0;
}