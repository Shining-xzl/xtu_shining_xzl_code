#include <cstdio>
using namespace std;
double a,b,c;

int main()
{
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
	{
		printf("%.5f\n",(a*b+b*(b-1))/(a+b)/(a+b-c-1));
	}
	return 0;
} 
