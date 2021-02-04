#include <cstdio>
#include <cstring>
using namespace std;
char sample[102];
int dp[102][102];

bool match(const char &a,const char &b)
{
	if(a=='('&&b==')') return true;
	if(a=='['&&b==']') return true;
	return false;
}

int Min(int a,int b)
{
	return a<b?a:b;
}

void putall(int start,int end)
{
	if(start>end) return;
	else if(start==end)
	{
		if(sample[end]=='('||sample[end]==')')
			printf("()");
		else printf("[]");
	}
	else
	{
		if(match(sample[start],sample[end])&&dp[start][end]==dp[start+1][end-1])
		{
			putchar(sample[start]);
			putall(start+1,end-1);
			putchar(sample[end]);
			return;
		}
		for(int i=start;i<end;i++)
			if(dp[start][i]+dp[i+1][end]==dp[start][end])
			{
				putall(start,i);
				putall(i+1,end);
				return;
			}
	}
}

void core_dp()
{
	int len=strlen(sample);
	for(int i=0;i<len;i++)
		dp[i][i]=1,dp[i+1][i]=0;
	for(int i=len-2;i>=0;i--)
		for(int j=i+1;j<len;j++)
		{
			dp[i][j]=j-i+1;
			if(match(sample[i],sample[j]))
				dp[i][j]=Min(dp[i][j],dp[i+1][j-1]);
			for(int mid=i;mid<j;mid++)
			{
				dp[i][j]=Min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
			}
		}
	putall(0,len-1);
	putchar('\n');
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int time,con=0;
	scanf("%d",&time);
	gets(sample);
	while(time--)
	{
		if(con++) putchar('\n');
		gets(sample);
		gets(sample);
		core_dp();
	}
	return 0;
}