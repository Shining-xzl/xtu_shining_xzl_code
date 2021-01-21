#include <cstdio>
using namespace std;

int main()
{
	int time,n,m;
	double g;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		g=(n+m)/2.0;
		if(n==m) printf("None\n");
		else if(m>n) printf("Alice %g\n",g-n);
		else printf("Bob %g\n",g-m);
	}
	return 0;
}
