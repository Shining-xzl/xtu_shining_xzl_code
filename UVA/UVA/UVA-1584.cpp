#include <cstdio>
#include <cstring>
using namespace std;
char s[102];
char ans[102];

void get_ans()
{
	memset(ans,0,sizeof(ans));
	short j,i,k,len=strlen(s);
	bool flag;
	for(i=0;i<len;i++)	ans[i]=s[i];
	for(i=1;i<len;i++)
	{
		flag=0;
		for(j=0;j<len;j++)
		{
			k=j+i;
			if(k>=len) k-=len;
			if(s[k]<ans[j])
			{
				flag=1;break;	
			}
			else if(s[k]==ans[j]) continue;
			else break;
		}
		if(flag)
			for(j=0;j<len;j++)
			{
				k=j+i;
				if(k>=len) k-=len;
				ans[j]=s[k];
			}
				
	}
	printf("%s\n",ans);
}

void initial()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&s);
		get_ans();
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	initial();
	return 0;
}
