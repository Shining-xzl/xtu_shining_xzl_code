#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int lim = 1003;
int a[1003],b[1003],n;
int pos[1003];
vector< int > son[lim];

void work()
{
	int op = 1,now,a,len;
	stack<int> SK;
	SK.push(b[0]);
	while(op < n)
	{
		now = b[op];
		while(1)
		{
			a = SK.top();
			if((pos[a] == 0) || (pos[a] + 1 < pos[now]) || (pos[a] + 1 == pos[now] && a > now))
			{
				son[a].push_back(now);
				SK.push(now);
				break;
			}
			else SK.pop();
		}
		++op;
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d:", i);
		len = son[i].size();
		for (int j = 0; j < len; ++j)
			printf(" %d", son[i][j]);
		printf("\n");
	}
}

int main()
{freopen("in.txt","r",stdin);
	while(scanf("%d",&n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]),pos[a[i]] = i;
		for (int i = 0; i <= n; ++i)
			son[i].clear();
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		work();
	}
	return 0;
} 
