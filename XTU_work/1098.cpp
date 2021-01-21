#include <stdio.h>
using namespace std;
bool is_prime[1000003];
int prime[1000003];
int a[80003],len;

void get_prime()
{
	int i,j;
	for(i=2;i<=1000000;i++)
	{
		prime[i]=prime[i-1];
		if(!is_prime[i])
		{
			a[++len]=i;
			prime[i]++;
		}
		for(j=1;j<=len&&i*a[j]<=1000000;j++)
		{
			is_prime[i*a[j]]=1;
			if(i%a[j]==0) break;
		}
	}
}

int main()
{
	get_prime();
	int time,a,b,temp;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(a==0) a=1;
		if(b==0) b=1;
		printf("%d\n",prime[b]-prime[a-1]);
	}
	return 0;
}
