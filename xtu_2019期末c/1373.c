#include <stdio.h>
#include <stdlib.h>

int main()
{
//    freopen("in.txt","r",stdin);
    int T;
    int x1,y1,r1;
    int x2,y2,r2,mr,xr;
    int cdis,ans,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&x1,&y1,&r1);
        scanf("%d%d%d",&x2,&y2,&r2);
        mr=(r1<r2?r1:r2);
        xr=(r1>r2?r1:r2);
        cdis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        l=(r1+r2);
        l*=l;
        if(l<cdis) ans=5;
        else if(l==cdis) ans=4;
        else if((xr-mr)*(xr-mr)<cdis&&cdis<l) ans=3;
        else if((xr-mr)*(xr-mr)==cdis) ans=2;
        else ans=1;
        printf("%d\n",ans);
    }
    return 0;
}
