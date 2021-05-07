#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;

struct order
{
	int t;
	queue<int> q;
};

map<int,order> ind;

struct person
{
	int id,k,tid[24],time,pretime;
	bool operator < (const person &a) const
	{
		return (a.pretime!=pretime) ? (pretime<a.pretime) : (id<a.id);
	}
}mm[6];

int main()
{
//	freopen("in.txt","r",stdin);
	int tid,num,t0,t,dt,n,m;
	int outtime,ans,N,con=0;
	while(scanf("%d",&n)&&n)
	{
		outtime=inf;
		ans=0;
		N=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d",&tid,&num,&t0,&t,&dt);
			N+=num;
			outtime=(outtime>t0?t0:outtime);
			order temp;
			temp.t=t;
			while(num--) temp.q.push(t0),t0+=dt;
			ind[tid]=temp;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&mm[i].id,&mm[i].k);
			mm[i].time=0;
			mm[i].pretime=0;
			for(int j=0;j<mm[i].k;j++)
				scanf("%d",&mm[i].tid[j]);
		}
		while(N)
		{
			int jump=inf;
			sort(mm,mm+m);
			for(int i=0;i<m;i++)
			{
				int nexttime=inf;
				if(mm[i].time>outtime)
				{
					nexttime=mm[i].time;
				}
				else
				{
					for(int j=0;j<mm[i].k;j++)
					{
						order &x=ind[mm[i].tid[j]];
						if(x.q.empty()) continue;
						if(x.q.front()<=nexttime)
							nexttime=x.q.front();
						if(x.q.front()<=outtime)
						{
							mm[i].pretime=outtime;
							nexttime=outtime+x.t;
							ans=(ans<nexttime?nexttime:ans);
							x.q.pop();
							N--;
							break;
						}
					}
					mm[i].time=nexttime;
				}
				jump=(jump>nexttime?nexttime:jump);
			}
			outtime=jump;
		}
		printf("Scenario %d: All requests are serviced within %d minutes.\n",++con,ans);
	}
	return 0;
}