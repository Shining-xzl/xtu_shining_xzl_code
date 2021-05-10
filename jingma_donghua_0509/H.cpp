#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int lim = 1e5+3;

int n;
long long ansa,ansb;
int a[lim],x;
int main()
{
	while(scanf("%d", &n) == 1)
	{
		ansa = ansb = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d",&a[i]),ansa += (long long)a[i];
		for (int i = 0; i < n; ++i)
			scanf("%d",&x),a[i] += x,ansb += (long long)x;
		sort(a,a+n);
		int op = 1;
		for (int i = n-1; i >= 0; --i)
		{
			if(op & 1) ansa += a[i];
			else ansb += a[i];
			++op;
		}
		if(ansa > ansb) printf("Alice\n");
		else if(ansb > ansa) printf("Bob\n");
		else printf("AEMSHANA\n");
	}
	return 0;
}