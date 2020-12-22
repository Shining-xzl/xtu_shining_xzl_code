#include <stdio.h>
#include <stdlib.h>

int f[50];
int q[100003],xlen=0;
int q1[100003],num[100003],lenc=0;

void xsort(int l,int r)//快速排序 
{
    int mid=q[(l+r)>>1];
    int a=l,b=r,temp;
    while(a<=b)
    {
        while(q[a]<mid) a++;
        while(q[b]>mid) b--;
        if(a<=b)
        {
            temp=q[a];
            q[a]=q[b];
            q[b]=temp;
            a++;
            b--;
        }
    }
    if(a<r) xsort(a,r);
    if(b>l) xsort(l,b);
}

void prime()
{
    f[1]=1;
    f[0]=1;
    int len=2,i,j,k;
    while(1)
    {
        f[len]=f[len-1]+f[len-2];
        if(f[len]>1e9) break;
        len++;
    }
    for(i=len;i>0;i--)
        for(j=i;j>0;j--)
            for(k=j;k>0;k--)
            {
                if(f[i]+f[j]+f[k]>0&&f[i]+f[j]+f[k]<=1e9)
                q[++xlen]=f[i]+f[j]+f[k];
            }
                
    xsort(1,xlen);
    for(i=1;i<=xlen;i++)
    {
        if(q[i]!=q[i-1])
            q1[++lenc]=q[i];
        num[lenc]++;
    }
}

int find(int x)//二分查找 
{
    int l=1,r=lenc;
    int mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(q1[mid]==x) return num[mid];
        else if(q1[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return 0;
}

int main()
{
    int T,n;
    prime();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",find(n));
    }
    return 0;
}
