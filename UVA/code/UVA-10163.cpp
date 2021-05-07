/*
���ִ�+dp
���������С�ػ�ֵ
dp��С��н�� 
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
int s[32];
int L,Y;
int dp[103];

bool check(int x)
{
	if(x==0)//ע�� 
	{
		Y=0;
		return 1;	
	}
	memset(dp,INF,sizeof(dp));
	dp[0]=0;
	int temp;
	for(int i=0;i<m;i++)
	{
		for(int j=n;j>=0;j--)//һ��Ҫ����,�������� 
		{
			if(dp[j]==INF) continue;
			temp=j+s[i]/x;
			if(temp>n) temp=n;//����Ҳǿ�Ƶ���n 
			if(dp[temp]>dp[j]+s[i])
				dp[temp]=dp[j]+s[i];
		}
	}
	if(dp[n]!=INF)//n���ֿ�����ػ� 
	{
		Y=dp[n];
		return 1;
	}
	else return 0;
}

void binary_find()//���ִ� 
{
	int l=0,r=1000;
	int mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			L=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
		for(int i=0;i<m;i++)
			scanf("%d",&s[i]);
		binary_find();
		printf("%d %d\n",L,Y);		
	}
	return 0;
} 
