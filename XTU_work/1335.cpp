#include <cstdio>
#include <cmath>
using namespace std;
int s[1003];

void prime()
{
	int i,j,temp,k,l;
	for(i=1;i<=1000;i++)
	{
		s[i]=0;
		temp=i*i;
		for(j=1;j<i;j++)
		{
			k=temp-j*j;
			l=sqrt(k);
			if(l*l==k) s[i]++;
		}
		s[i]=(s[i]<<2)+4;
	}
}

int main()
{
	int time,r;
	prime();
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&r);
		printf("%d\n",s[r]);
	}
	return 0;
}
