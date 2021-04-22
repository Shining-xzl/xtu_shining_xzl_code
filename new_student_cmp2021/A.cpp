#include <cstdio>
using namespace std;

int main()
{
	double r;
	int s;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %lf", &s,&r);
		if(s&1)
			printf("%.2f\n",s*s/4.0 );
		else printf("%d\n",s*s/4 );
	}
	return 0;
}