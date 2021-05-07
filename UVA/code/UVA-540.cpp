#include <cstdio>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int num_team,i,num,x,con=0;
	char c[10];
	while(scanf("%d",&num_team)&&num_team)
	{
		queue<int> hq,q[1003];
		map<int,int> hg;
		for(i=0;i<num_team;i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&x);
				hg[x]=i;
			}
		}
		printf("Scenario #%d\n",++con);
		while(1)
		{
			scanf("%s",c);
			if(c[0]=='S') break;
			else if(c[0]=='E')
			{
				scanf("%d",&x);
				i=hg[x];
				if(q[i].empty())
					hq.push(i);
				q[i].push(x);
			}
			else if(c[0]=='D')
			{
				i=hq.front();
				x=q[i].front();
				printf("%d\n",x);
				q[i].pop();
				if(q[i].empty())
					hq.pop();
			}
		}
		printf("\n");
	} 
	return 0;
}
