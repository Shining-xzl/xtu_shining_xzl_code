#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;

int main()
{
	priority_queue<LL,vector<LL>,greater<LL> > q;
	int n,count = 0;
	LL health = 0ll,x,temp;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lld", &x);
		q.push(x);
		health += x;
		++count;
		while(health < 0)
		{
			temp = q.top(); q.pop();
			--count;
			health -= temp;
		}
	}
	printf("%d\n",count);
	return 0;
}