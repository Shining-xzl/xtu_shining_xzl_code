#include <cstdio>
#include <cstring>
using namespace std;
const int inf=1<<12;
const int INF=0x3f3f3f3f;
int n,m;
int sample[131];
int dp[inf+3][inf+3];

inline int Min(int a,int b) { return a<b?a:b; }
inline int Max(int a,int b) { return a>b?a:b; }

int get_ans(int s,int a)
{
	int &ans=dp[s][a];
	if(ans<INF) return ans;
	ans=inf;
	int con=0;
	for(int i=0;i<n;i++)
		if((s&sample[i])==a) con++;
	if(con<=1) return ans=0;
	for(int i=0;i<m;i++)
	{
		if(s&(1<<i)) continue;
		ans=Min(ans,Max(get_ans(s|(1<<i),a),get_ans(s|(1<<i),a|(1<<i)))+1);
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char temp[12];
	while(scanf("%d%d",&m,&n)==2)
	{
		if(m==n&&m==0) break;
		for(int i=0;i<n;i++)
		{
			sample[i]=0;
			scanf("%s",temp);
			for(int j=0;temp[j]!=0;j++)
				if(temp[j]=='1')
					sample[i]|=(1<<j);
		}
		memset(dp,INF,sizeof(dp));
		printf("%d\n",get_ans(0,0));
	}	
	return 0;
}