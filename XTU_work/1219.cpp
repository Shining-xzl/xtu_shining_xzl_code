#include <cstdio>
using namespace std;

int main()
{
	int time;
	scanf("%d",&time);
	__int64 n,m;
	while(time--)
	{
		scanf("%I64d%I64d",&n,&m);
		n=(n*(n-1))>>1;
		n+=m;
		printf("%I64d\n",n);
	}
	return 0;
}
