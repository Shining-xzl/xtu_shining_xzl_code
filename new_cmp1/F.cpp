#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int lim = 2e5+4;

struct Ts
{
	int p,a,b;
	bool operator < (const Ts &x) const 
	{
		return p < x.p;
	}
}s[lim];
int n;
bool vis[lim];
int p1,p2,p3;

void process()
{
	p1 = p2 = p3 = 0;
	while(s[p1].a != 1 && s[p1].b != 1 && p1 < n) ++p1;
	while(s[p2].a != 2 && s[p2].b != 2 && p2 < n) ++p2;
	while(s[p3].a != 3 && s[p3].b != 3 && p3 < n) ++p3;
}

int get_ans(int x)
{
	if(x == 1)
	{
		while(p1 < n && ( (s[p1].a != 1 && s[p1].b != 1) || vis[p1] ))
			++p1;
		if(p1 == n) return -1;
		vis[p1] = 1;
		return s[p1++].p;
	}
	else if(x == 2)
	{
		while(p2 < n && ( (s[p2].a != 2 && s[p2].b != 2) || vis[p2] ))
			++p2;
		if(p2 == n) return -1;
		vis[p2] = 1;
		return s[p2++].p;
	}
	else if(x == 3)
	{
		while(p3 < n && ( (s[p3].a != 3 && s[p3].b != 3) || vis[p3] ))
			++p3;
		if(p3 == n) return -1;
		vis[p3] = 1;
		return s[p3++].p;
	}
	return -1;
}

void work()
{
	memset(vis,0,sizeof(vis));
	int m,x;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&x);
		printf("%d ", get_ans(x));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&s[i].p);
	for (int i = 0; i < n; ++i)
		scanf("%d",&s[i].a);
	for (int i = 0; i < n; ++i)
		scanf("%d",&s[i].b);
	sort(s,s+n);
	process();
	work();
	return 0;
}