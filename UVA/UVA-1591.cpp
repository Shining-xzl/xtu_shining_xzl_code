#include <cstdio>
using namespace std;
typedef long long LL;

int main()
{
	LL n,sq,sp,temp;
	LL K,A,B;
	while(scanf("%lld%lld%lld",&n,&sp,&sq)==3)
	{
		K=1e+18;
		for(int i=0;i<32;i++)
			for(int j=0;j<32;j++)
				{
					temp=((sp*(n-1)+((sp*(n-1))<<i))>>j)+sq;
					if((temp>=n*sq)&&(K>temp))
					{
						K=temp;
						A=i;
						B=j;
					}
				}
		printf("%lld %lld %lld\n",K,A,B);
	}
	return 0;
}