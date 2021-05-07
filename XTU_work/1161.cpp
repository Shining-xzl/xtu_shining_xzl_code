#include <cstdio>

using namespace std;

const int MOD = 100003;
int f[1003];

int main()
{
	f[0] = 1;
	f[2] = 3;
	for (int i = 4; i <= 1000; i += 2)
	{
		f[i] = f[i-2] * 3;
		for (int j = 0; j < i-2; j += 2)
		{
			f[i] += f[j] * 2;
			f[i] %= MOD;
		}
		f[i] %= MOD;
	}
	int n;
	while(scanf("%d",&n) == 1 && n) printf("%d\n", f[n]);
	return 0;
}
