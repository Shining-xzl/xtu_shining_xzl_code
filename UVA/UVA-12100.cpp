#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

void core()
{
	queue< pair<int,int> > q;
	priority_queue< int,vector<int>,less<int> > xq;
	pair<int,int> temp;
	int n,m,x,con=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		q.push(make_pair(x,i));
		xq.push(x);
	}
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp.first==xq.top())
		{
			con++;
			xq.pop();
			if(temp.second==m)
			{
				printf("%d\n",con);
				return;
			}
		}
		else q.push(temp);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--) core();
	return 0;
}
