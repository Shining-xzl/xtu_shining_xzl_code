#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n,i,k,a;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		i=0;
		a=0;
		k=n;
		while(k>0) k/=10,i++;
		k=n;
		while(k>0)
		{
			a+=pow(k%10,i);
			k/=10;
		}
		if(a==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
