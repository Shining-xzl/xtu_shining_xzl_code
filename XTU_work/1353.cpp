#include <cstdio>
#include <cstring>
using namespace std;
int len;
char s[33];

int right(int &n)
{
	long long i,temp,x,k,max=0;
	int l;
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			s[i]-='0';
		else s[i]-=55;
		if((long long)s[i]+1>max) 
			max=(long long)s[i]+1;
	}
	for(i=max;i<17;i++)
	{
		temp=0;
		k=1;
		l=len-1;
		while(l>=0)
		{
			x=(long long)s[l];
			temp+=x*k;
			k*=i;
			if(temp>n) break;
			l--;
		}
		if(temp==(long long)n) return (int)i;
	}
	
	return 0;
}

int main()
{
	int n,i,k;
	while(scanf("%s%d",s,&n)==2)
	{
		len=strlen(s);
		i=right(n);
		if(i) printf("%d\n",i);
		else printf("Impossible\n");
	}
	return 0;
}
