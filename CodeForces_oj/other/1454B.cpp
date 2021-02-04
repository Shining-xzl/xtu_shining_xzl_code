#include <cstdio>
#include <map>
using namespace std;

void work()
{
	int n,x;
	scanf("%d",&n);
	//printf("**%d\n",n);
	map<int,int> p;
	map<int,int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(p.count(x)==1)
			p[x]=-1;
		else p[x]=i;
	}
	for(it=p.begin();it!=p.end();it++)
	{
		if(it->second!=-1)
		{
			printf("%d\n",it->second);
			return;
		}
	}
	printf("-1\n");
}

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
		work();
	return 0;
}