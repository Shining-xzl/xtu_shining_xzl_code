#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int map[10003],cnt;
set<int> all;
int n;
int dp[2503][52],c[2503];
long long p[2503];

int Min(int a,int b)
{
	return a<b?a:b;
}

/*
�����ÿ�δ�ÿ���Ѷ�ȡ���ӣ�ÿ��ֻ��ȡͬһ����ģ���ͬ��С�Ŀ���һ������
����һ����������set�������壬��ÿһ�ֵ������յ�λ�á�
��ͬһ�ֵ�����k���д��ڣ�����Ҫȡk�Σ��������һ����ĵ�������һ����ĵ��ӳ�����ͬһ�ѣ����ν���������������һ��
dpĿ�ģ������������νӣ�
dp[n][k]����ʾȡ����n�֣����һ��ȡ��k��ʱ��״̬
dpת�ƺ����ԣ���n��n-1�й�ͬ��һ�ѣ�����Խ���ת�� 

����������p�����i�ֵ�������Щ���д���
��ô������� 
 
������������������
longlong ����λ����Ҫ��1LL,��Ȼ��� 
*/ 

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int x,m,pre,Case=0;
	while(scanf("%d",&n)==1)
	{
		all.clear();
		cnt=0;
		memset(map,0,sizeof(map));
		memset(dp,INF,sizeof(dp));
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			pre=-1;
			while(m--)
			{
				scanf("%d",&x);
				if(pre!=x)
				{
					if(map[x]==0) map[x]=(++cnt);
					p[map[x]]+=(1LL<<i);
					c[map[x]]++;
					all.insert(x);
				}
				pre=x;
			}
		}
		set<int>::iterator it;
		pre=0;
		int i=1,Min1=0,Min2;
		for(it=all.begin();it!=all.end();it++)
		{
			x=map[*it];
			Min2=INF;
			for(int j=0;j<n;j++)
			{
				if(((1ll<<j)&p[pre])&&((1ll<<j)&p[x]))//��ͬһ�ѣ�λ���㱣���еĶѣ�c�������� 
				{
					for(int k=0;k<n;k++)
					{
						if(k==j&&c[x]!=1) continue;//���ֻ��һ���У������ֱ��ת�� 
						if((1ll<<k)&p[x])
						{
							dp[i][k]=Min(dp[i][k],dp[i-1][j]+c[x]-1);
							Min2=Min(Min2,dp[i][k]);
						}
					}
				}
			}
			for(int j=0;j<n;j++)
			{
				if((1ll<<j)&p[x])
				{
					dp[i][j]=Min(dp[i][j],Min1+c[x]);
					Min2=Min(Min2,dp[i][j]);
				}
			}
			Min1=Min2;
			pre=x;
			i++;
		}
		printf("Case %d: %d\n",++Case,Min1*2-n-1);
	}
	return 0;
} 
