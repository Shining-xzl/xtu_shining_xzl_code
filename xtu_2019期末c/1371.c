#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T,ans,temp,i;
    char s[203];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        ans=0;
        temp=20;
        for(i=1;s[i]!='\0';i++)
        {
            if(s[i]=='O') 
            {
                ans+=temp;
                if(temp<50)
                    temp+=10;    
            }
            else if(s[i]=='X') temp=20;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
