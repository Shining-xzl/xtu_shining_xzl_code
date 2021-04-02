#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

#define PR pair< char,char >

vector< stack< PR > > q;

void show()
{
	int len = q.size();
	printf("%d pile%s remaining:", len, len == 1 ? "" : "s");
	for (int i = 0; i < len; ++i)
		printf(" %d", q[i].size());
	printf("\n");
}

bool check(int i,int next)
{
	if(q[i].top().first == q[next].top().first
	|| q[i].top().second == q[next].top().second)
		return 1;
	return 0;
}

void work()
{
	int len,next;
	bool flag = 1;
	vector< stack< PR > >::iterator it;
	while(flag)
	{
		flag = 0;
		len = q.size();
		for (int i = 0; i < len; ++i)
		{
			next = i - 3;
			if(next >= 0 && check(i,next))
			{
				q[next].push( q[i].top() );
				q[i].pop();
				it = q.begin() + i;
				flag = 1;
				break;
			}
			next = i - 1;
			if(next >= 0 && check(i,next))
			{
				q[next].push( q[i].top() );
				q[i].pop();
				it = q.begin() + i;
				flag = 1;
				break;
			}
		}
		if(flag && it->empty())
			q.erase(it);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char s[3];
	while(scanf("%s",s) == 1)
	{
		if(!strcmp(s,"#")) break;
		q.clear();
		q.resize(52,stack< PR >());
		q[0].push( PR(s[0],s[1]) );
		for (int i = 1; i < 52; ++i)
		{
			scanf("%s",s);
			q[i].push( PR(s[0],s[1]) );
		}
		work();
		show();
	}
	return 0;
} 
