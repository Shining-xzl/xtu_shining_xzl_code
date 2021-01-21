#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int s[1003];
char a[3];

inline bool cmp1(const int &a,const int &b)
{
    return a<b;
}

inline bool cmp2(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int time,i;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d",&n);
        scanf("%s",&a);
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        if(a[0]=='A') sort(s,s+n,cmp1);
        else sort(s,s+n,cmp2);
        for(i=0;i<n-1;i++)
            printf("%d ",s[i]);
        printf("%d\n",s[n-1]);
    }
    return 0;
}
