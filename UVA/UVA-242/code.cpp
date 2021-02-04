//����ƫ���������������� 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int S,N;
int dp[1103];
vector<int> s[103];

inline bool cmp(const int &a,const int &b)
{
	return a>b;
}

int get_max_coverage(vector<int> &s)
{
	int op=0;
	memset(dp,INF,sizeof(dp));
	dp[0]=0;
	do//����dp����ÿ�����ֽ��м��飬dp���������С���� 
	{
		op++;
		for(int i=s.size()-1;i>=0&&op-s[i]>=0;i--)//��Ϊ�Ǵ�С�������Կ���Խ��ֱ������ 
		{
			if(dp[op-s[i]]+1<dp[op]&&dp[op-s[i]]+1<=S)//����С��S 
				dp[op]=dp[op-s[i]]+1;
		}
	}while(dp[op]<INF);//�޷��ϳɼ����� 
	return op-1;//����Ҫ��1 
}

int main()
{
	int n,ansp,ans,anslen;
	while(scanf("%d",&S)&&S)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&n);
			s[i].resize(n);
			while(n--) scanf("%d",&s[i][n]);	
			sort(s[i].begin(),s[i].end(),cmp);//�������� 
		}
		sort(s,s+N);//�ֵ������� 
		ans=0;
		ansp=0;
		anslen=INF;
		for(int i=0;i<N;i++)
		{
			n=get_max_coverage(s[i]);//��ȡ�����ƴ�յ���ֵ 
			if(n>ans||(n==ans&&s[i].size()<anslen))//�������� 
			{
				ans=n;
				ansp=i;
				anslen=s[i].size();
			}
		}
		printf("max coverage =%4d :",ans);
		for(int i=s[ansp].size()-1;i>=0;i--)
		{
			printf("%3d",s[ansp][i]);
		}
		printf("\n");
	}
	return 0;
} 

