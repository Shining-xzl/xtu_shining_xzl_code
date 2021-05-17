#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	double ans,a,b,s;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf %lf %lf", &a,&b,&s);
		if(s < 1e-5) ans = 1;
		else if(a*b - s < -(1e-5)) ans = 0;
		else ans  = 1 - s/a/b - s*log(a*b/s)/(a*b);
		ans *= 100;
		printf("%.6f%%\n", ans);

	}
	return 0;
} 
