#include <cstdio>
#include <algorithm>

using namespace std;
int n,m;
char a[2003],b[2003];
long long f[4000004],op = 0;
void process()
{
	long long t;
	for (int i = 0; i < m; ++i)
	{
		t = 0;
		for (int j = i; j < m; ++j)
		{
			t = t * 131 + b[j] - 'a' + 1;
			f[op++] = t;
		}
	}
	sort(f,f+op);
}

int main()
{
	scanf("%d %d", &n,&m);
	scanf("%s %s", a,b);
	process();
	int ans = 0;
	long long t;
	for (int i = 0; i < n; ++i)
	{
		t = 0;
		for (int j = i; j < n; ++j)
		{
			t = t * 131 + a[j] - 'a' + 1;
			if(*lower_bound(f,f+op,t) != t)
			{
				ans += n - j;
				break;
			}	
		}
	}
	printf("%d\n", ans);
	return 0;
}
