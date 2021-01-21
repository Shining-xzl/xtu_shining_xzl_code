#include <cstdio>
using namespace std;
const int TNT=32000;
int prime[3500],len;
bool is_prime[TNT];
int k[]={100000000,10000000,1000000,100000,10000,1000,100,10,1};


void get_prime()
{
	int i,j;
	for(i=2;i<=TNT;i++)
	{
		if(!is_prime[i])
			prime[++len]=i;
		for(j=1;j<=len&&prime[j]*i<=TNT;j++)
		{
			is_prime[prime[j]*i]=1;
			if(i%prime[j]==0) break;
		}
	}
}

inline bool if_prime(int n)
{
	if(n<=1) return 0;
	int i=1;
	while(prime[i]*prime[i]<=n)
	{
		if(n%prime[i]==0) return 0;
		i++;
	}
	return 1;
}

inline bool right(int n)
{
	if(!if_prime(n)) return 0;
	int i=0;
	while(n<k[i]) i++;
	while(i<9)
	{
		n%=k[i];
		if(n==0) return 1;
		if(n<k[i+1]) return 0;
		if(!if_prime(n)) return 0;
		i++;
	}
	return 1;
}

int main()
{
	int time,n;
	scanf("%d",&time);
	get_prime();
	while(time--)
	{
		scanf("%d",&n);
		if(right(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
