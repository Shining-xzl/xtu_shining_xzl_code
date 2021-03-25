#include <cstdio>
#include <cstring>
using namespace std;
int n,m;

int in_point[103];

struct node
{
	int son,next;
}s[5003];

int op = 0, head[103];

void add(int a,int b)
{
	++op;
	s[op].son = b;
	s[op].next = head[a];
	head[a] = op;
}

int main()
{
	int i,j,v;
	while(scanf("%d %d", &n,&m) == 2)
	{
		if(n == 0 && m == 0) break;
		memset(in_point, 0, sizeof(in_point));
		memset(head, -1, sizeof(head));
		op = 0;
		while(m--)
		{
			scanf("%d %d", &i,&j);
			++in_point[j];
			add(i,j);
		}
		int qu[103],l = 1,r = 0;
		for(i = 1; i <= n; ++i)
			if(in_point[i] == 0)
				qu[++r] = i;
		while(l <= r)
		{
			i = qu[l++];
			j = head[i];
			while(j != -1)
			{
				v = s[j].son;
				--in_point[v];
				if(in_point[v] == 0)
					qu[++r] = v;
				j = s[j].next;
			}
		}
		for(i = 1; i <= n; ++i)
			printf("%d ", qu[i]);
		printf("\n");
	}
	return 0;
} 
