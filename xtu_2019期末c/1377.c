#include <stdio.h>

const int LIM=1e6+2;
int prime[1003],len;
int is_prime[1003];
int sumx[1000003];

void primex()
{
    int i,j,temp;
    for(i=2;i<=1000;i++)
    {
        if(is_prime[i]==0)
            prime[++len]=i;
        for(j=1;j<=len&&prime[j]*i<=1000;i++)
        {
            is_prime[prime[j]*prime[i]]=1;
            if(i%prime[j]==0) break;
        }
    }//这是一个素数表，不要太在意他的写法 
    for(i=1;i<=LIM;i++)
    {
        sumx[i]=0;
        temp=i;
        j=1;
        while(prime[j]*prime[j]<=temp)
        {
            if(temp%prime[j]==0)
            {
                sumx[i]++;
                while(temp%prime[j]==0) temp/=prime[j];
            }
            j++;
        }
        if(temp>1) sumx[i]++;
        sumx[i]+=sumx[i-1];
    }
}

int main()
{
    int T,a,b;
    primex();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",sumx[b]-sumx[a-1]);
    }
    return 0;
}
