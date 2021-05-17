/*
容斥原理
*/
#include <cstdio>
using namespace std;
typedef long long LL;

int main()
{
	int n,res,p,k,T;
	scanf("%d", &T);
	while(T--)
	{	
		scanf("%d %d", &n,&k);
		res = n;
		p = -1;
		while(n > 0)
		{
			n /= k;
			res += n * p;
			p *= -1;
		}
		printf("%d\n", res);
	}
	return 0;
} 
