#include <cstdio>
using namespace std;
int gcd(unsigned int a,unsigned int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	unsigned int a,b,c;
	while(scanf("%u%u%u",&a,&b,&c)==3)
	{
		if(a==0&&b==0&&c==0) break;
		if(a==0&&b==0) printf("No\n");
		else if(a==0||b==0)
		{
			if(a<b) a=b;
			if(c%a==0) printf("Yes\n");
			else printf("No\n");
		}
		else
		{
			if(c%gcd(a,b)==0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}