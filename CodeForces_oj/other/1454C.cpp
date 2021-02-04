#include <cstdio>
#include <map>
using namespace std;

void work()
{
	int n,a,b,q=-1,ans=1e9,temp,x;
	scanf("%d",&n);
	map<int,int> p;
	map<int,int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i==1) a=x;
		if(i==n) b=x;
		if(x!=q)
		{
			if(p.count(x)==1)
				p[x]++;
			else p[x]=1;
			q=x;
		}
	}
	for(it=p.begin();it!=p.end();it++)
	{
		temp=it->second+1;
		if(it->first==a) temp--;
		if(it->first==b) temp--;
		if(temp<ans) ans=temp;
	}
	printf("%d\n",ans);
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