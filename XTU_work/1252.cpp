#include <cstdio>
#include <cstring>
using namespace std;

int num_c[102][30],num_l[102][30];
char s[103][103];
int n,m;

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(num_l,0,sizeof(num_l));
		memset(num_c,0,sizeof(num_c));
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				num_c[i][s[i][j]-'a']++;
				num_l[j][s[i][j]-'a']++;
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(num_c[i][s[i][j]-'a']==1&&num_l[j][s[i][j]-'a']==1)
					printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}