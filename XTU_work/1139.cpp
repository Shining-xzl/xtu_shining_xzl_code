#include <cstdio>
using namespace std;
const int TNT=10000;
int prime[1500],len;
bool is_prime[TNT+3];

void get_prime()
{
	int i,j;
	for(i=2;i<TNT;i++)
	{
		if(!is_prime[i])
			prime[++len]=i;
		for(j=1;j<=len&&prime[j]*i<=TNT;j++)
		{
			is_prime[prime[j]*i]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}

inline bool right(int x)
{
	int i=1;
	while(i<=len&&prime[i]*prime[i]<=x)
	{
		if(x%prime[i]==0) return 0;
		i++;
	}
	return 1;
}

inline bool find(int x)
{
	int i=1;
	while(i<=len&&prime[i]*prime[i]<x)
	{
		if(x%prime[i]==0) 
		{	
			if(right(x/prime[i]))
				return 1;
			else return 0;
		}
		i++;
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	get_prime();
	int time,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&x);
		if(find(x)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
