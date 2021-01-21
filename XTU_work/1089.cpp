#include <stdio.h>

int s[1300],b[1300],len=0;
int n;
bool is_prime[10003];

void prime()
{
    int i,j;
    for(i=2;i<=10000;i++)
    {
        if(is_prime[i]==0)
        {
        	s[++len]=i;
        	b[len]=s[len]*s[len];
		} 
        for(j=1;j<=len&&s[j]*i<=10000;j++)
        {
            is_prime[i*s[j]]=1;
            if(i%s[j]==0) break;
        }
    }
}

int main()
{
	int i,con;
	bool flag;
    prime();
    while(scanf("%d",&n)!=EOF)
    {
        i=1;flag=0;
        while(n>1&&b[i]<=n)
        {
        	con=0;
        	while(n%s[i]==0)
        	{
        		con++;
        		n/=s[i];
			}
			if(con>0)
			{
				if(flag) printf("*");
        		printf("%d",s[i]);
        		if(con>1) printf("^%d",con);
        		flag=1;
			}	
			i++;
		}
		if(flag&&n>1) printf("*%d",n);
		else if(n>1) printf("%d",n);
		printf("\n");
    }
    return 0;
}

