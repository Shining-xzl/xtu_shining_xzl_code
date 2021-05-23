// 相对位置不变

#include <cstdio>
#include <algorithm>
using namespace std;

const char *p[] ={"L","R","Fell off","Turning"};
struct ants
{
	int point,id;
	char di;
	bool operator < (const ants &x) const
	{
		return point < x.point;
	}
}s[10003],t[10003];
int n,T,len;
int num[10003];
int po[10003];

int main()
{
	int cas = 0,time;
	scanf("%d", &time);
	while(time--)
	{
		scanf("%d%d%d", &len,&T,&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %c ",&s[i].point,&s[i].di);
			t[i].point = s[i].point;
			t[i].id = i;
			if(s[i].di == 'R') s[i].point += T;
			else s[i].point -= T;
		}
		sort(s,s+n);
		sort(t,t+n);
		printf("Case #%d:\n", ++cas);
		for (int i = 0; i < n; ++i)
		{
			if(s[i].point < 0 || s[i].point > len) 
			{
				num[t[i].id] = -1;
				po[t[i].id] = 2;
			}
			else
			{
				num[t[i].id] = s[i].point;
				if((i != 0 && s[i].point == s[i-1].point) || (i != n-1 && s[i].point == s[i+1].point))
					po[t[i].id] = 3;
				else if(s[i].di == 'R')
					po[t[i].id] = 1;
				else po[t[i].id] = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(num[i] == -1) printf("%s\n", p[po[i]]);
			else printf("%d %s\n",num[i],p[po[i]]);
		}
		putchar('\n');
	}	
	return 0;
}