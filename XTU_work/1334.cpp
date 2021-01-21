#include <cstdio>
#include <algorithm>
using namespace std;
__int64 s[54];
int n;

__int64 gcd(__int64 a,__int64 b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int time,i,j,k;
    __int64 min,temp,a;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%I64d",&s[i]);
        sort(s+1,s+n+1);
        min=1e+18;
        for(i=1;i<n;i++)
        {
            if(min<s[i]) break;
            for(j=i+1;j<n;j++)
            {
                temp=s[j]*s[i]/gcd(s[j],s[i]);
                if(min<s[j]) break;
                if(min<temp) continue;
                for(k=j+1;k<=n;k++)
                {
                    if(min<s[k]) break;
                    a=s[k]*temp/gcd(s[k],temp);
                    if(a<min) min=a;
                }
            } 
        }
        printf("%I64d\n",min);
    }
    return 0;
}
