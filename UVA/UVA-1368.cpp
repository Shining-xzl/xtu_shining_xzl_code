#include <cstdio>
#include <cstring>
using namespace std;

char s[52][1002];
char k[4]={'A','C','G','T'};
short num[4];

void initial()
{
	int n,m,i,j,ans=0,p;
	scanf("%d%d",&m,&n);
	memset(s,0,sizeof(s));
	for(i=1;i<=m;i++) scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{
		memset(num,0,sizeof(num));
		for(j=1;j<=m;j++)
		{
			if(s[j][i]=='A') num[0]++;
			else if(s[j][i]=='C') num[1]++;
			else if(s[j][i]=='G') num[2]++;
			else num[3]++;
		}
		p=0;
		for(j=1;j<4;j++)
			if(num[j]>num[p]) p=j;
		ans+=m-num[p];
		printf("%c",k[p]);
	}
	printf("\n%d\n",ans);
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
