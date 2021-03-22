#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int lim=50004;
const int INF=0x3f3f3f3f;

#define Min(x,y) ((x)<(y)?(x):(y))
int dis[lim];
int v[lim],len=0;
struct valx
{
	int num,val;
	valx(int a,int b):num(a),val(b) {}
	bool operator < (const valx &a) const
	{
		return num>a.num;
	}
};

int main()
{
	memset(dis,INF,sizeof(dis));
	int n,x,now;
	scanf("%d",&n);
	scanf("%d",&x);
	dis[0]=1;
	for(int i=1;i<n;++i)
	{
		scanf("%d",&now);
		if(dis[now%x]==INF)
			dis[now%x]=now/x,v[len++]=now%x;
	}
	priority_queue<valx> q;
	for(int i=0;i<x;i++)
		if(dis[i]!=INF)
			q.push(valx(dis[i],i));
	valx temp(0,0);
	int val,num,valp,nump;
	while(!q.empty())
	{
		temp=q.top();
		q.pop();
		val=temp.val;
		num=temp.num;
		if(num>dis[val]) continue;
		for(int i=0;i<len;i++)
		{
			nump=num+dis[v[i]]+(val+v[i])/x;
			valp=(val+v[i])%x;
			if(dis[valp]>nump)
			{
				dis[valp]=nump;
				q.push(valx(nump,valp));
			}
		}
	}

	int m;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&now);
		if(now==0||now/x>=dis[now%x]) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
