#include <cstdio>
#include <climits>
using namespace std;
const int TNT=65536;

int prime[TNT],len;
bool is_prime[TNT+3];
int s[20][100];
 
void get()
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

bool find(int x)
{
	int i=1;
	while(i<=len&&prime[i]*prime[i]<=x)
	{
		if(x%prime[i]==0) return 0;
		i++;
	}
	return 1;
}

int main()
{
	get();
	int con=0,len=0,n,p=1,i,j;
	int temp;
	s[1][1]=2;
	s[1][2]=3;
	s[1][3]=5;
	s[1][4]=7;
	len=4;
	while(len)
	{
		n=len;
		len=0;
		for(i=1;i<=n;i++)
			printf("%d %d\n",++con,s[p][i]);
		p++;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=9;j+=2)
			{
				temp=s[p-1][i]*10+j;
				if(find(temp))
					s[p][++len]=temp;
			}
		}
	}
	return 0;
}
