#include <stdio.h>
#include <math.h>
using namespace std;
int s[10003];

void prime()
{
	s[0]=1;
	for(int i=1;i<=10000;i++)
		s[i]=s[i-1]*i%10007;
}

int main()
{
	prime();
	int a;
	while(scanf("%d",&a))
	{
		if(a==-1) break;
		printf("%d\n",s[a]);
	}
	return 0;
}
