#include <cstdio>
#include <cstring>
using namespace std;
const int TNT=1003;
char s[TNT];
int num[100],len;

int main()
{
    int time,i,temp;
    bool flag;
    scanf("%d",&time);
    while(time--) 
    {
        flag=1;
        temp=0;
        memset(num,-1,sizeof(num));
        scanf("%s",&s);
        len=0;
        while(s[len]!='\0') len++;
        if(len&1) flag=0;
        if(flag)
        {
            for(i=0;i<len;i++)
            {
                if(num[s[i]-65]==-1) num[s[i]-65]=i;
                else if((i-num[s[i]-65])&1) num[s[i]-65]=-1,temp+=2;
                else break;
            }
            if(temp!=len) flag=0; 
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
