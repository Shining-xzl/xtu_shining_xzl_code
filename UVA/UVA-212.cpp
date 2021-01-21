#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const char *head[6]={" Patient          Operating Room          Recovery Room\n",
					" #  Name     Room#  Begin   End      Bed#  Begin    End\n",
					" ------------------------------------------------------\n",
					"Facility Utilization\n",
					"Type  # Minutes  % Used\n",
					"-------------------------\n"};
int n,m,T,t1,t2,t3,k;

struct patiens
{
	string name;
	int otime,ctime,id,sotime,ootime,sctime,octime,roomid,bedid;
}q[102];

struct room
{
	int id,stime;
	room(int id,int stime):id(id),stime(stime){};
	bool operator < (const room &a) const
	{
		return stime==a.stime ? id>a.id : stime>a.stime;
	}
};

bool cmp(const patiens &a,const patiens &b)
{
	return a.sctime==b.sctime ? a.id<b.id : a.sctime<b.sctime;
}

bool cmp1(const patiens &a,const patiens &b)
{
	return a.id<b.id;
}

int main()
{
	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)==1)
	{
		scanf("%d%d%d%d%d%d",&m,&T,&t1,&t2,&t3,&k);
		priority_queue<room> rq;
		vector<int> roomtime(n+1,0);
		for(int i=1;i<=n;i++)
			rq.push(room(i,T*60));
		room temp(1,0);
		for(int i=0;i<k;i++)
		{
			cin>>q[i].name>>q[i].otime>>q[i].ctime;
			q[i].id=i+1;
			temp=rq.top();
			rq.pop();
			q[i].roomid=temp.id;
			q[i].sotime=temp.stime;
			q[i].ootime=temp.stime+q[i].otime;
			q[i].sctime=q[i].ootime+t1;
			temp.stime=q[i].ootime+t2;
			rq.push(temp);
			roomtime[temp.id]+=q[i].otime;
		}
		sort(q,q+k,cmp);
		vector<int> bed(m+1,T*60),bedtime(m+1,0);
		int overtime=0;
		for(int i=0;i<k;i++)
		{
			int j;
			for(j=1;j<=m;j++)
				if(bed[j]<=q[i].ootime) break;
			q[i].bedid=j;
			q[i].octime=q[i].sctime+q[i].ctime;
			bedtime[j]+=q[i].ctime;
			bed[j]=q[i].octime+t3;
			overtime=(overtime<q[i].octime?q[i].octime:overtime);
		}
		for(int i=0;i<3;i++)
			printf("%s",head[i]);
		sort(q,q+k,cmp1);
		for(int i=0;i<k;i++)
		{
			cout<<right<<setw(2)<<q[i].id<<"  ";
			cout<<left<<setw(9)<<q[i].name<<' ';
			printf("%2d  %3d:%02d  %3d:%02d     ",q[i].roomid,q[i].sotime/60,q[i].sotime%60,q[i].ootime/60,q[i].ootime%60);
            printf("%2d  %3d:%02d  %3d:%02d\n",q[i].bedid,q[i].sctime/60,q[i].sctime%60,q[i].octime/60,q[i].octime%60);
		}
		printf("\n");
		for(int i=3;i<6;i++)
			printf("%s",head[i]);
		for(int i=1;i<=n;i++)
		{
			printf("Room %2d %7d %7.2f\n",i,roomtime[i],roomtime[i]*100.0/(overtime-T*60));
		}
		for(int i=1;i<=m;i++)
		{
			printf("Bed  %2d %7d %7.2f\n",i,bedtime[i],bedtime[i]*100.0/(overtime-T*60));
		}
		printf("\n");
	}
	return 0;
}
