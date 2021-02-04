#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
char s[5005],t[55];
int lens,lent;
int dp[5003][53];

inline int Min(int a,int b)
{
	return a<b?a:b;
}

bool check_dp(int stand)
{
	memset(dp,INF,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<=lens;i++)
	{
		if(dp[i][lent]<=stand)//�л��ϵ�,ǰi�����Էֳ�����С��stand�Ŀ飬��i��Ϊ�µ���� 
			dp[i][0]=0;
		for(int j=0;j<=lent;j++)//ˢ�������չ 
		{
			dp[i+1][j+1]=Min(dp[i+1][j+1],dp[i][j]+(s[i+1]==t[j+1]?0:1));//�滻���жϣ� 
			dp[i][j+1]=Min(dp[i][j+1],dp[i][j]+1);//�� 
			dp[i+1][j]=Min(dp[i+1][j],dp[i][j]+1);//ɾ 
		}
	}
	return dp[lens][lent]<=stand;
}

void binary_search()//��Ϊ��������ɾ�����������������ֻ��lent�� 
{
	int l=0,r=lent,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(check_dp(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%s",t+1,s+1);
		lens=strlen(s+1);
		lent=strlen(t+1);
		binary_search();
	}
	return 0;
} 
