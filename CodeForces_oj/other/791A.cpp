#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int ans;
	double a,b;
	scanf("%lf%lf",&a,&b);
	ans=(int)(log(b/a)/log(1.5));
	ans+=1;
	printf("%d\n",ans);
	return 0;
}
