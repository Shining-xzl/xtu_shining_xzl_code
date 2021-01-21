#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003];
int n,m;

void read(int &a)
{
    char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    a=0;
    while(c<='9'&&c>='0')
    {
        a=(a<<3)+(a<<1)+(c^48);
        c=getchar();
    }
    return;
}

void put(int x)
{
    char s[17];
    int len=0;
    while(x>0)
    {
        s[++len]=x%10+48;
        x/=10;
    }
    while(len) putchar(s[len--]);
    putchar('\n');
}

int find(int x)
{
    int l=1,r=n,mid;
    while(l<=r)
    {
        mid=r+l>>1;
        if(a[mid]==x)
        {
            r=mid-1;
        }
        else if(a[mid]>x) r=mid-1;
        else 
        {
            l=mid+1;
        }
    }
    while(a[l]<x&&l<=n) l++;
    return l;
}

int main()
{
    int i,x;
    read(n);
    read(m);
    for(i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    while(m--)
    {
        read(x);
        put(find(x));
    }
    return 0;
} 
