#include <stdio.h>

int right(int x,int k)
{
	int s[60];
	int len=0,i;
	while(x>0)
	{
		s[++len]=x%k;
		x/=k;
	}
	for(i=1;i<=len;i++)
	{
		if(s[i]!=s[len-i+1]) return 0;
	}
	return 1;
}

int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==0) printf("2\n");
		for(i=2;i<=n+1;i++)
			if(right(n,i)==1)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;	
} 
