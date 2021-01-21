#include <stdio.h>
#include <cstring>
using namespace std;

const int MOD=1000000007;
int ans[1003][4]; 
char s[1003];

int main()
{
	int time,i,len,j;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<4;i++)
			ans[0][i]=0;
		if(s[0]=='L') 
			ans[0][0]=1;
		for(i=1;i<len;i++)
		{
			for(j=0;j<4;j++)
				ans[i][j]=ans[i-1][j];
			if(s[i]=='L') ans[i][0]+=1;
			else if(s[i]=='O') ans[i][1]+=ans[i-1][0];
			else if(s[i]=='V') ans[i][2]+=ans[i-1][1];
			else if(s[i]=='E') ans[i][3]+=ans[i-1][2];
			for(j=0;j<4;j++)
				if(ans[i][j]>=MOD)
					ans[i][j]-=MOD;
		}
		printf("%d\n",ans[len-1][3]);
	}
	return 0;
} 
