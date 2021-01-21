#include <stdio.h>
#include <math.h>
int s[6600],len=0;
unsigned int n;
bool is_prime[65538];

void prime()
{
    int i,j;
    for(i=2;i<=65536;i++)
    {
        if(is_prime[i]==0)
            s[++len]=i;
        for(j=1;j<=len&&s[j]*i<=65536;j++)
        {
            is_prime[i*s[j]]=1;
            if(i%s[j]==0) break;
        }
    }
}

bool right()
{
    if(n==1) return 0;
    int i=1,k=(int)sqrt((double)n);
    while(i<=len&&s[i]<=k)
    {
        if(n%s[i]==0) return 0;
        i++;
    }
    return 1;
}

int main()
{
    prime();
    while(scanf("%u",&n)==1)
    {
        if(n==0) break;
        if(right()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
