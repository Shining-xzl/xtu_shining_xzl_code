#include <cstdio>
using namespace std;
const int TNT=50000;
int a,b;
int prime[5200],len;
bool is_prime[TNT+2];

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
			if(i%prime[j]==0)
				break;
		}
	}
}

int main()
{
	get_prime();
	int time,ans,i,con;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		a+=b;
		ans=1;
		i=1;
		while((i<=len)&&(a>1))
		{
			con=0;
			while(a%prime[i]==0)
			{
				con++;
				a/=prime[i];
			}
			if(con)
				ans*=(con+1);
			i++;
		}
		if(a>1) ans<<=1;
		printf("%d\n",ans);
	}
	return 0;
}
