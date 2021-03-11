#include <stdio.h>

#define lim 100003
int prime[lim+3],isprime[lim+3],len;

void get_prime()
{	
	int i,j; 
	len=0;
	for(i=2;i<lim;i++)
	{
		if(!isprime[i])
			prime[++len]=i;
		for(j=1;j<=len&&i*prime[j]<lim;j++)
		{
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	return;
}

#define Max(x,y) ((x)>(y)?(x):(y))

int main()
{
	get_prime();
	int n,i=1;
	scanf("%d",&n);
	while(prime[i]*prime[i]<=n)
	{
		if(n%prime[i]==0)
		{
			printf("%d\n",Max(prime[i],n/prime[i]));
			break;
		}
		i++;
	}
	return 0;
}
