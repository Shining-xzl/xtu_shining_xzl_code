#include <cstdio>
using namespace std;
short s[100003];

void prime()
{
	int i,k;
	s[11]=1;
	s[1001]=1;
	s[1111]=1;
	for(i=12;i<=100000;i++)
	{
		k=i-11;
		if(k>0&&s[k]>0&&(s[i]==0||(s[i]>s[k]+1)))
			s[i]=s[k]+1;
		k=i-1001;
		if(k>0&&s[k]>0&&(s[i]==0||(s[i]>s[k]+1)))
			s[i]=s[k]+1;
		k=i-1111;
		if(k>0&&s[k]>0&&(s[i]==0||(s[i]>s[k]+1)))
			s[i]=s[k]+1;
	}
}

int main()
{
	prime();
	int time,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		printf("%d\n",s[n]);
	}
	return 0;
}
