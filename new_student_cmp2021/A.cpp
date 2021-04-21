#include <cstdio>
using namespace std;

int main()
{
	double s,r;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf %lf", &s,&r);
		printf("%g\n",s*s/4 );
	}
	return 0;
}