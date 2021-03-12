
//easy stack used
#include <cstdio>
#include <stack>
using namespace std;

#define PR pair<int,int> 
PR stand[30];
int n,ans;
char s[1003];

int main()
{
	scanf("%d",&n);	
	char c;
	int a,b;
	bool ok;
	for(int i=1;i<=n;i++)
	{
		scanf(" %c %d %d",&c,&a,&b);
		stand[c-'A'].first=a;
		stand[c-'A'].second=b;
	}
	while(scanf("%s",s)==1)
	{
		ans=0;
		ok=1;
		stack<PR> p;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='(') continue;
			else if(s[i]==')')
			{
				PR a1,a2;
				if(p.size()<=1) continue;
				a1=p.top();p.pop();
				a2=p.top();p.pop();
				if(a1.first!=a2.second)
				{
					ok=0;break;
				}
				ans+=a1.second*a1.first*a2.first;
				p.push(pair<int,int>(a2.first,a1.second));
			}
			else p.push(stand[s[i]-'A']);
		}
		if(ok) printf("%d\n",ans);
		else printf("error\n");
	}
	return 0;
} 
