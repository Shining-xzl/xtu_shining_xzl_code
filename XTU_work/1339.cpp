#include <cstdio>
using namespace std;
const int TNT=1000100;

bool is_prime[TNT];
int sum[TNT];
int s[79000],len;

void prime()
{
	int i,j;
	for(i=2;i<=TNT;i++)
	{
		if(!is_prime[i])
			s[++len]=i;
		for(j=1;j<=len&&s[j]*i<=TNT;j++)
		{
			is_prime[s[j]*i]=1;
			if(i%s[j]==0) break;
		}
	}
	for(i=2;i<=len;i++)
	{
		j=s[i]+s[i-1]>>1;
		if(is_prime[j]) sum[j]=1; 
	}
	for(i=1;i<=TNT;i++)
		sum[i]+=sum[i-1];
}

int main()
{
	prime();
	int time,a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",sum[b]-sum[a-1]);
	}
	return 0;
}
