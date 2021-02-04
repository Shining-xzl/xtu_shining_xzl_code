#include <cstdio>
using namespace std;
typedef long long LL;

const int T=1e5+3;
bool is_prime[T];
int prime[10003],con;

void get_prime()
{
	for(int i=2;i<=T;i++)
	{
		if(!is_prime[i])
			prime[++con]=i;
		for(int j=1;j<=con&&i*prime[j]<=T;j++)
		{
			is_prime[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	get_prime();
	int time,max,p,i,num;
	LL x,temp;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%lld",&x);
		temp=x;
		i=1;
		max=0;
		while(temp>1&&i<=con)
		{
			num=0;
			while(temp%prime[i]==0)
			{
				num++;
				temp/=prime[i];
			}
			if(num>max)
			{
				max=num;
				p=prime[i];
			}
			i++;
		}
		if(max==0)
		{
			printf("1\n");
			printf("%lld\n",x);
		}
		else
		{
			printf("%d\n",max);
			temp=1;
			for(int i=1;i<max;i++)
				printf("%d ",p),temp*=p;
			printf("%lld\n",x/temp);
		}
	}
	return 0;
}