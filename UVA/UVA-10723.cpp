//�ַ� A to X ������� 
#include <cstdio>
#include <cstring>
using namespace std;

char s[34],t[34];
unsigned int dp[34][34],num[34][34];
int lens,lent;

void read(char *s)// ÿ�ж���
{
	char c=getchar();
	int len=0;
	while(c!='\n'&&c!='\r'&&c!=EOF)
	{
		if(c>='A'&&c<='X')
			s[len++]=c;
		c=getchar();
	}
	s[len]='\0';
}

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int time,Case=0;
	scanf("%d ",&time);
	while(time--)
	{
		read(s);
		read(t);
		memset(dp,0x3f3f3f3f,sizeof(dp));
		memset(num,0,sizeof(num));
		lens=strlen(s);
		lent=strlen(t);
		num[0][0]=1;//��¼���� 
		dp[0][0]=0;//��ֵҪ����ã�dp[i][j]������s����i����t����j��ʱ����̴����� 
		for(int i=0;i<=lens;i++)
		{
			for(int j=0;j<=lent;j++)
			{
				if(i==0&&j==0) continue;
				if(i==0||j==0)//ֻ�е��� 
				{
					dp[i][j]=i+j;
					num[i][j]=1;
				}
				else
				{
					if(s[i-1]==t[j-1])//���ַ���ȣ���֤��dp[i-1][j-1]һ����ǰ����� 
					{
						dp[i][j]=dp[i-1][j-1]+1; 
						num[i][j]=num[i-1][j-1];
					}
					else
					{
						if(dp[i-1][j]==dp[i][j-1])//����ȵ�������ͬ 
						{
							dp[i][j]=dp[i-1][j]+1;
							num[i][j]=num[i-1][j]+num[i][j-1];//�ؼ� 
						}
						else if(dp[i-1][j]>dp[i][j-1])
						{
							dp[i][j]=dp[i][j-1]+1;
							num[i][j]=num[i][j-1];
						}
						else
						{
							dp[i][j]=dp[i-1][j]+1;
							num[i][j]=num[i-1][j];
						}
					}
				}
			}
		}
		printf("Case #%d: %u %u\n",++Case,dp[lens][lent],num[lens][lent]);
	}
	return 0;
} 
