#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	n=n*m;
	if(n&1) printf("%d\n",n-1>>1);
	else printf("%d\n",n>>1);
	return 0;
}
