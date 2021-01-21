#include <cstdio>
using namespace std;
bool is_prime[5000002];
int prime[350000],len;
int sum[5000002];

void get_prime()
{
    is_prime[0]=1;
    is_prime[1]=1;
    int i,j;
    for(i=2;i<=5000000;i++)
    {
        if(!is_prime[i])
            prime[++len]=i;
        for(j=1;j<=len&&prime[j]*i<=5000000;j++)
        {
            is_prime[i*prime[j]]=1;
            if(!(i%prime[j]))
             break;
        }
    }
    sum[0]=0;
    sum[1]=0;
    sum[2]=0;
    for(i=3;i<=5000000;i++)
    {
        sum[i]=sum[i-1];
        if((!is_prime[i])&&(!is_prime[i-2]))
            sum[i]++;
    }
}

int main()
{
    get_prime();
    int time,a,b,ans;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&a,&b);
        ans=sum[b]-sum[a-1];
        if((!is_prime[a])&&(!is_prime[a-2])) ans--;
        if((!is_prime[a+1])&&(!is_prime[a-1])) ans--; 
        printf("%d\n",ans);
    }
    return 0;
}
