#include <cstdio>
using namespace std;
const int TNT=500000;
int sum[(TNT<<1)+2];
bool is_prime[TNT+2];
int s[42000],len;

void read(int &a)
{
	a=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0')
	{
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
}

void prime()
{
	int i,j,k=TNT<<1,temp;
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
	for(i=1;i<=len;i++)
	{
		if(s[i]*s[i+1]>k) break;
		for(j=i+1;j<=len;j++)
		{
			temp=s[i]*s[j];
			if(temp>k) break;
			else sum[temp]=1;
		}
	}
	for(i=1;i<=k;i++)
		sum[i]+=sum[i-1];
}

void put(int a)
{
	char c[12];
	int len=0;
	if(a==0)
	{
		putchar('0');
	}
	else
	{
		while(a>0)
		{
			c[++len]=a%10+48;
			a/=10;
		}
		while(len)
			putchar(c[len--]);
	}
	putchar('\n');
}

int main()
{
	int time,n,m;
	prime();
	scanf("%d",&time);
	while(time--)
	{
		read(n);
		read(m);
		put(sum[m]-sum[n-1]);
	}
	return 0;
}
