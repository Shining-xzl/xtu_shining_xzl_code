//easy Stack used

#include <cstdio>
#include <stack>
using namespace std;

int stand[1003];

int main()
{
	int n,op;
	while(scanf("%d",&n)&&n)
	{
		while(scanf("%d",&stand[1])&&stand[1])
		{
			for(int i=2;i<=n;i++)
				scanf("%d",&stand[i]);
			stack <int> SK;
			op=1;
			for(int i=1;i<=n;i++)
			{
				while(op<=n&&(SK.empty()||SK.top()!=stand[i]))
					SK.push(op++);
				if(SK.top()==stand[i])
					SK.pop();
			}
			if(SK.empty()) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
} 
