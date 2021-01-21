#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1000000007;
int ans[5003][2][3];
char s[5003];


int main()
{
	int len,i,k;
	int end_ans;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		end_ans=0;
		k=s[len-1]-'0';
		ans[0][0][0]=1;
		ans[0][1][0]=0;
		ans[0][1][1]=0;
		ans[0][1][2]=0;
		ans[0][1][k%3]=1;
		if(k>0)
			end_ans+=ans[0][1][0];
		for(i=1;i<len;i++)
		{
			k=s[len-i-1]-'0';
			ans[i][0][0]=ans[i-1][0][0]+ans[i-1][1][0];
			if(ans[i][0][0]>=MOD)
				ans[i][0][0]-=MOD;
			ans[i][0][1]=ans[i-1][0][1]+ans[i-1][1][1];
			if(ans[i][0][1]>=MOD)
				ans[i][0][1]-=MOD;
			ans[i][0][2]=ans[i-1][0][2]+ans[i-1][1][2];
			if(ans[i][0][2]>=MOD)
				ans[i][0][2]-=MOD;
			ans[i][1][k%3]=ans[i-1][0][0]+ans[i-1][1][0];
			if(ans[i][1][k%3]>=MOD)
				ans[i][1][k%3]-=MOD;
			ans[i][1][(k+1)%3]=ans[i-1][0][1]+ans[i-1][1][1];
			if(ans[i][1][(k+1)%3]>=MOD)
				ans[i][1][(k+1)%3]-=MOD;
			ans[i][1][(k+2)%3]=ans[i-1][0][2]+ans[i-1][1][2];
			if(ans[i][1][(k+2)%3]>=MOD)
				ans[i][1][(k+2)%3]-=MOD;
			if(k>0)
				end_ans+=ans[i][1][0];
			if(end_ans>=MOD) 
				end_ans-=MOD;	
		}
		printf("%d\n",end_ans);
	}
	return 0;
} 
