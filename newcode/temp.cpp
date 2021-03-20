#include<bits/stdc++.h>
  
using namespace std;
int n,now,num;
const int LIM=0x3f3f3f3f;
bool ok[12];
int f[12][12];
int stand;
int dp[12][12][2];
  
#define Min(x,y) ((x)<(y)?(x):(y))
  
int main()
{
    int p,x;
    int ans,Case=0;
    char c;
    while(scanf("%d%d%d",&n,&now,&num)==3&&n&&now&&num)
    {
        memset(dp,LIM,sizeof(dp));
        memset(f,0,sizeof(f));
        memset(ok,0,sizeof(ok));
		dp[now][now][1]=dp[now][now][0]=0;
        stand=(1<<num)-1;
        for(int o=1;o<=n;o++)
        {
   			scanf("%d",&p);
       		for(int i=1;i<=p;i++)
      		{
      	   		scanf("%d",&x);
       	   		f[o][o]|=(1<<(x-1));
     	    }
			scanf(" %c ",&c);
        	if(c=='Y') ok[o]=1; 
		}
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                f[i][j]=f[i][j-1]|f[j][j]; 
		ans=LIM;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j][1]=abs(now-j)+abs(j-i);       
                dp[i][j][0]=abs(now-i)+abs(i-j);
            }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                if(f[i][j]==stand)
                for(int k=i;k<=j;k++)
                {
                    if(ok[k])
                    {
                        int temp=LIM;
                        temp=Min(temp,dp[i][j][1]+abs(i-k)+abs(now-k));
                        temp=Min(temp,dp[i][j][0]+abs(j-k)+abs(now-k));
                        ans=Min(ans,temp);
                    }
                }
            }
        if(Case) printf("\n");
        printf("Test case #%d: ",++Case);
    	if(ans<LIM) printf("%d\n",ans);
    	else printf("Impossible\n");
	}
    return 0;
}
