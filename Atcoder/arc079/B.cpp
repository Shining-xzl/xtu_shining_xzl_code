#include <cstdio>

using namespace std;
typedef long long LL;
LL k;
LL ans[56];
int n = 50;

int main()
{
	scanf("%lld", &k);
	LL a,b;
	a = k/n;
	b = k%n;
	for (int i = 1; i <= n; ++i)
		ans[i] = i + a;
	--ans[50 - b];
	printf("50\n");
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}