#include <stdio.h>
#include <stdlib.h>

__int64 gcd(__int64 a,__int64 b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
__int64 ansa,ansb,k;
__int64 a[102],b[103];
int main()
{
    int T,i,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%I64d",&b[i]);
        ansa=a[n];
        ansb=b[n];
        k=gcd(ansa,ansb);
        ansa/=k;
        ansb/=k;
        for(i=n-1;i>0;i--)
        {    
            ansb+=a[i]*ansa;
            ansa*=b[i];
            k=ansa;
            ansa=ansb;
            ansb=k;
            k=gcd(ansa,ansb);
            ansa/=k;
            ansb/=k;
        }
        printf("%I64d",ansb);
        if(ansa!=1) printf("/%I64d",ansa);
        printf("\n");
    }
    return 0;
}
