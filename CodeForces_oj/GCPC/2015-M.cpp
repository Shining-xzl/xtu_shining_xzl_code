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
	scanf("%d",&x);//x为a[1],默认升序
	dis[0]=0;//初始化，不要忘记
	for(int i=1;i<n;++i)
	{
		scanf("%d",&now);
		if(dis[now%x]==INF)
			dis[now%x]=now,v[len++]=now%x;//构建同余系，原始数据
	}
	priority_queue<valx> q;
	for(int i=0;i<x;i++)
		if(dis[i]!=INF)
			q.push(valx(dis[i],i));
	valx temp(0,0);
	int val,num,valp,nump;
	while(!q.empty())//跑最短路，利用原始数据构建其他数据
	{
		temp=q.top();
		q.pop();
		val=temp.val;
		num=temp.num;
		if(num>dis[val]) continue;
		for(int i=0;i<len;i++)//这题卡常数，建议保存原始数据
		{
			nump=num+dis[v[i]];
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
		if(now>=dis[now%x]) printf("TAK\n");//判断已知最小的d与其比较
		else printf("NIE\n");
	}
	return 0;
}
