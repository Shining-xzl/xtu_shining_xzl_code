#include <cstdio>
#include <set>
#include <vector>
using namespace std;
bool right(vector<int> &x,int n)
{
	for(unsigned int i=0;i<n;i++)
		if(x[i]!=0) return false;
	return true;
}

void core()
{
	set< vector<int> > home;
	vector<int> now,pre;
	unsigned int n,i,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		now.push_back(temp);
	}
	if(right(now,n))
	{
		printf("ZERO\n");
		return;
	}
	home.insert(now);
	while(1)
	{
		pre=now;
		for(i=0;i<n-1;i++)
		{
			now[i]=pre[i+1]-pre[i];
			if(now[i]<0) now[i]=-now[i];
		}
		now[i]=pre[n-1]-pre[0];
		if(now[i]<0) now[i]=-now[i];
		if(home.count(now)==1)
		{
			printf("LOOP\n");
			return;
		}
		else home.insert(now);
		if(right(now,n))
		{
			printf("ZERO\n");
			return;
		}
	}
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
		core();
	return 0;
}