//此题编码越界

#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int K=256;

vector<int> v;
char s[1000];
map<int,char> m;

void prime()
{
	int x,temp;
	for(int i=1;i<=8;i++)
	{
		x=1<<i;
		temp=i*K;
		for(int j=0;j<x-1;j++)
		{
			v.push_back(j+temp);
		}
	}
}

void build_map()
{
	m.clear();
	for(int i=0;s[i]!='\0';i++)
		m[v[i]]=s[i];
}

int read_x(int num)
{
	int res=0;
	char c;
	while(num)
	{
		c=getchar();
		if(c=='1')
			res=res*2+1,num--;
		else if(c=='0')
			res=res*2,num--;
	}
	return res;
}

void work()
{
	int now=read_x(3);
	int x;
	while(now!=0)
	{
		x=read_x(now);
		while(x!=((1<<now)-1))
		{
			// printf("%d\n",K*(now)+x);
			printf("%c",m.count(K*now+x)==1 ? m[K*now+x] : 0);
			x=read_x(now);
		}
		now=read_x(3);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	prime();
	while(gets(s))
	{
		build_map();
		work();
		printf("\n");
		gets(s);
	}
	return 0;
}