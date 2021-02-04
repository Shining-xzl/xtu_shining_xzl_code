//翻译偏离轨道。。。。。。 

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
	do//正向dp，对每个数字进行检验，dp储存的是最小张数 
	{
		op++;
		for(int i=s.size()-1;i>=0&&op-s[i]>=0;i--)//因为是从小到大，所以可以越界直接跳出 
		{
			if(dp[op-s[i]]+1<dp[op]&&dp[op-s[i]]+1<=S)//必须小于S 
				dp[op]=dp[op-s[i]]+1;
		}
	}while(dp[op]<INF);//无法合成即跳出 
	return op-1;//返回要减1 
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
			sort(s[i].begin(),s[i].end(),cmp);//逆向排序 
		}
		sort(s,s+N);//字典序排序 
		ans=0;
		ansp=0;
		anslen=INF;
		for(int i=0;i<N;i++)
		{
			n=get_max_coverage(s[i]);//获取最大能拼凑的数值 
			if(n>ans||(n==ans&&s[i].size()<anslen))//长度优先 
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

