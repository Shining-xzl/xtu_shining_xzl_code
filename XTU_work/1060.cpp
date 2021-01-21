#include <cstdio>
#include <cstring>
using namespace std;
char s[30];

bool check()
{
    int k=0,i=0,ans=0,len;
    bool flag=0;
    while(s[i]==' ') i++;
    if(s[i]=='+'||s[i]=='-') 
    {
        i++;
        while(s[i]==' ') i++;
    }
    if(s[i]=='0') flag=1;
    len=strlen(s);
    len--;
    while(s[len]==' ') len--;
    if(i>len) return 0;
    while(i<=len)
    {
        if(s[i]<'0'||s[i]>'9') return 0;
        ans=ans*10+s[i]-48;
        k++;
        i++;
    }
    if(flag)
    {
        if(k==1&&ans==0) return 1;
        //k==1可要可不要。
        else return 0;
    } 
    return 1;
}

int main()
{    
    while(gets(s))
    {
        if(check())
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}