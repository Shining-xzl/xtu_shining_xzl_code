#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[2];
    int n,i,j;
    while(scanf("%s",s)!=EOF)
    {
        n=s[0]-64;
        for(i=n;i>0;i--)
        {
            for(j=n-i;j>0;j--)
                putchar(' ');
            putchar(i+64);
            for(j=i*2;j>1;j--)
                putchar(' ');
            putchar(i+64);
            putchar('\n');
        }
        for(i=n;i>0;i--)
            putchar(' ');
        putchar('X');
        putchar('\n');
        for(i=1;i<=n;i++)
        {
            for(j=n-i;j>0;j--)
                putchar(' ');
            putchar(i+64);
            for(j=i*2;j>1;j--)
                putchar(' ');
            putchar(i+64);
            putchar('\n');
        }
    }
    return 0;
}
