#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
const int lim = 1003;

int b[lim];
int n,m;

struct fish
{
	int now,id;
	bool operator < (const fish &x) const 
	{
		return now < x.now;
	}
};

#define Min(x,y) ((x)<(y)?(x):(y))

void work()
{
	priority_queue<fish> q;
	int res = 0;
	fish temp;
	for (int i = 0; i < n; ++i)
	{
		temp.id = i;
		scanf("%d %d", &temp.now, &b[i]);
		q.push(temp);
	}
	while(m > 0)
	{
		temp = q.top(); q.pop();
		if (temp.now == 0) break;
		res += temp.now;
		temp.now -= b[temp.id];
		if (temp.now < 0) temp.now = 0;
		m--;
		q.push(temp);
	}
	printf("%d\n",res);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n,&m);
		work();	
	}
	return 0;
}