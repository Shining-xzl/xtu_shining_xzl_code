#include <cstdio>
using namespace std;

long long s[17];

bool right(int x)
{
	for(int i=2;i<=15;i++)
		if(x%(s[i]-1)==0) return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	s[0]=1LL;
	for(int i=1;i<=15;i++)
	{
		s[i]=s[i-1]*2;
	}
	int time;
	long long x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%lld",&x);
		if(right(x)) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
 } 
