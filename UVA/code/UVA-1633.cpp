#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1e9+7; 
int n,k;
bool is_palindromic[13][1<<11];
int dp[403][1<<13];

void dfs(int n,int x)
{
	is_palindromic[n][x]=1;
	if(n+2>11) return;//n�����10 
	dfs(n+2,(x<<1)+1+(1<<n+1));
	dfs(n+2,x<<1);
}

void prime_process()//dfs���� 
{
	dfs(1,1);
	dfs(1,0);
	dfs(2,3);
	dfs(2,0);
}

/*
dp[n][s]��ʾ����nλ��ǰk������״̬Ϊsʱ�Ŀ��ø��� 
״̬ת��ʱ����s��ĩλ��0(1)���ɣ��ж��Ƿ���ģ�ת�Ƶ�dp[n+1][s'] 
PS��������kλ�Ļ���ʱ��һ������k-1(k-2)���ӻ��ģ���һ�������ж��ӻ��ģ�
��˲����� k-1(k-2)�Ļ���ʱ��һ�������ڴ���k�Ļ��ġ�����֤�� 
*/
int solve()//״ѹDP 
{
	if(n<k) return 1<<n;//������� 
	memset(dp,0,sizeof(dp));
	int temp1;
	for(int i=0;i<(1<<k);i++)
		if(!is_palindromic[k][i]) dp[k][i]=1;//��ֵ����ʼ������Ϊk�������ɴ˴�ת�� 
	for(int i=k;i<n;i++)
		for(int j=0;j<(1<<k);j++)
		{
			if(dp[i][j]==0) continue;
			temp1=j+(1<<k);//temp1ΪĩΪ��1��jΪ��0
			/*
				���߷�����
				��k+1λ�����ģ��Һ�kλ������ 
			*/ 
			if((!is_palindromic[k+1][temp1])&&(!is_palindromic[k][temp1>>1])) dp[i+1][temp1>>1]=(dp[i+1][temp1>>1]+dp[i][j])%MOD;
			if((!is_palindromic[k+1][j])&&(!is_palindromic[k][j>>1])) dp[i+1][j>>1]=(dp[i+1][j>>1]+dp[i][j])%MOD;
		}
	int ans=0;
	for(int i=0;i<(1<<k);i++)
		ans=(ans+dp[n][i])%MOD;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	prime_process();//Ԥ�������(palindromic)�� 
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&k);
		printf("%d\n",solve());
	} 
	return 0;
} 
