#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

typedef unsigned long long LL;
map< LL, int > num;
int all_num;
char s[1000003];

int find(int pos)
{
	int a = 1;
	++pos;
	while(a != 0)
	{
		if(s[pos] == '[') ++a;
		else if(s[pos] == ']') --a;
		++pos;
	}
	return pos - 1;
}



void build(int l,int r,LL k)
{
	if(l > r) return;
	int ll,rr;
	LL a = 0ll;
	if(s[l] == '[')
	{
		ll = l;
		rr = find(l);
		build(ll + 1, rr - 1, k * 2);
		build(rr + 2, r, k);
	}
	else
	{
		while(s[l] >= '0' && s[l] <= '9')
		{
			a = (a<<3) + (a<<1) + (s[l] ^ 48);
			++l;
		}
		++all_num;
		a = a * k;
		if(num.find(a) == num.end()) num[a] = 1;
		else ++num[a];
		build(l + 1,r,k);
	}
}

int main()
{
	map< LL, int >::iterator it;
	int time,ans;
	scanf("%d", &time);
	while(time--)
	{
		num.clear();	
		all_num = 0;
		scanf("%s", s);
		build(0,strlen(s) - 1,1);
		ans = 1e9;
		for(it = num.begin(); it != num.end(); ++it)
			if(all_num - it->second < ans)
				ans = all_num - it->second;
		printf("%d\n", ans);
	}
	return 0;
} 
