/*
stl容器。。。。。。。。
结构体封装
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct PK
{
	deque< int > all;
	vector< deque<int> > pile;
	int op;
	void init(int now[])
	{
		pile.clear();
		for (int i = 0; i < 7; ++i)
			pile.push_back( deque<int>(1,now[i]) );
		all.clear();
		for (int i = 7; i < 52; ++i)
			all.push_back( now[i] );
		op = 0;
	}
	bool check(int a,int b,int c)
	{
		if(a + b + c == 10
		|| a + b + c == 20
		|| a + b + c == 30)
			return 1;
		else return 0;
	}
	void work()
	{
		int a = all.front(),b,c,len;
		bool flag = 0;
		all.pop_front();
		pile[op].push_back(a);
		while(pile[op].size() >= 3 && flag == 0)
		{
			a = pile[op].front(); pile[op].pop_front();
			b = pile[op].front(); pile[op].pop_front();
			c = pile[op].back(); pile[op].pop_back();
			if(check(a,b,c))
			{
				all.push_back(a);
				all.push_back(b);
				all.push_back(c);
			}
			else 
			{
				pile[op].push_front(b);
				b = pile[op].back(); pile[op].pop_back();
				if(check(a,b,c))
				{
					all.push_back(a);
					all.push_back(b);
					all.push_back(c);
				}
				else
				{
					pile[op].push_front(a);
					a = pile[op].back(); pile[op].pop_back();
					if(check(a,b,c))
					{
						all.push_back(a);
						all.push_back(b);
						all.push_back(c);
					}
					else
					{
						pile[op].push_back(a);
						pile[op].push_back(b);
						pile[op].push_back(c);
						flag = 1;
					}
				}
			}
		}
		if(pile[op].empty())
			pile.erase(pile.begin() + op);
		else ++op;
		if(op >= pile.size())
			op = 0;
	}
	int over()
	{
		if(pile.empty()) return 1;
		else if(all.empty()) return -1;
		else return 0;
	}
	bool operator < (const PK &x) const
	{
		if(op != x.op)
			return op < x.op;
		if(all != x.all)
			return all < x.all;
		return pile < x.pile;
	}
};
set<PK> library;
int main()
{
	int x[56],num;
	PK ans;
	while(scanf("%d",&x[0]) == 1 && x[0])
	{
		library.clear();
		for (int i = 1; i < 52; ++i)
			scanf("%d",&x[i]);
		ans.init(x);
		num = 7;
		while(ans.over() == 0 && library.count(ans) == 0)
		{
			library.insert(ans);
			ans.work();
			++num;
		}
		if(ans.over() == 1) 
			printf("Win :");
		else if(ans.over() == -1) 
			printf("Loss:");
		else printf("Draw:");
		printf(" %d\n", num);
	}
	return 0;
} 
