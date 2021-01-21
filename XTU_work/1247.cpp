#include <cstdio>
using namespace std;
short ans[1003][2700],num[1003];

void  o_o(short a[],short c[],short b)
{
    short i;
    for(i=1;i<=num[b-1];i++)
        c[i]=a[i]*b;
    num[b]=num[b-1];
    for(i=1;i<num[b];i++)
        if(c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    while(c[num[b]]>9)
    {
        c[num[b]+1]=c[num[b]]/10;
        c[num[b]]%=10;
        num[b]++;
    }
}

void initial()
{
    ans[1][1]=1;
    ans[0][1]=1;
    num[0]=1;
    num[1]=1;
    for(short i=2;i<=1000;i++)
        o_o(ans[i-1],ans[i],i);
}

int main()
{
    initial();
    int time,a,b;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",ans[a][b]);
     } 
    return 0;
}
