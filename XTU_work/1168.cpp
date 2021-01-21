#include <cstdio>
using namespace std;
const int MOD=1000003;
int s[1003][2];

int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==1) printf("%d\n",m);
		else if(n==2) printf("%d\n",m*(m-1));
		else if(m==2&&(n&1==1)) printf("0\n");
		else if(m==2&&(n&1==0)) printf("2\n");
		else
		{
			s[3][1]=m*(m-1);
			s[3][0]=m*(m-1)*(m-2)%MOD;
			for(i=4;i<=n;i++)
			{
				s[i][1]=s[i-1][0];
				s[i][0]=s[i-1][1]*(m-1)+s[i-1][0]*(m-2);
				s[i][0]%=MOD;
			} 
			printf("%d\n",s[n][0]);
		}
	}
	return 0;
}
