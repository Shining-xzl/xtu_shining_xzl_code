#include <stdio.h>

__int64 dp[103][103][12];

void prime()
{
/*
dp[i][k][j]表示共有i个块，当前第j列有k个块的情况
本解法采用递增的方式，分析可知递增与递减的answer一样 
*/
    dp[1][1][1]=1;
    int i,j,k,l,temp;
    for(i=2;i<=100;i++)
    {
        dp[i][i][1]=1;
        for(j=2;j<=10;j++)
        {
            temp=j*(j-1)/2;
            for(k=j;k+temp<=i;k++)
            {
                for(l=k-1;l>0;l--)
                {
                    dp[i][k][j]+=dp[i-k][l][j-1];
                }
            }
        }
    }
}

int main()
{
    int T,n,m,i;
    __int64 sum;
    prime();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        sum=0;
        for(i=n;i>=0;i--)
            sum+=dp[n][i][m];
        printf("%I64d\n",sum);
    }
    return 0;
}
