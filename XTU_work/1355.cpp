#include <cstdio>
using namespace std;
const int G=3000000;
long long sum[G+3];
bool is_prime[G+3];
int prime[G+3],num;

void get_prime()
{
    int i,j,temp,con,x;
    sum[1]=1;
    for(i=2;i<=G;i++)
    {
        if(!is_prime[i])
        {
            prime[++num]=i;
            sum[i]=i-1;
        }
        else
        {
            j=1;
            temp=i;
            sum[i]=1;
            while(prime[j]*prime[j]<=temp)
            {
                con=0;
                x=1;
                while(temp%prime[j]==0)
                {
                    con++;
                    temp/=prime[j];
                    x*=prime[j];
                }
                if(con)
                    sum[i]=sum[i]*(prime[j]-1)*(x/prime[j]);
                j++;
            }
            if(temp>1)
                sum[i]*=(temp-1);
        }
        for(j=1;j<=num&&i*prime[j]<=G;j++)
        {
            is_prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
        sum[i]+=sum[i-1];
    }
}

int main()
{
    get_prime();
    int time,a,b;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&a,&b);
        printf("%I64d\n",sum[b]-sum[a-1]);
    }
    return 0;
}
