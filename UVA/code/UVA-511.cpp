#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool equal(double a,double b)
{
	a=a-b;
	if(a<0) a=-a;
	if(a>1e-6) return false;
	else return true;
}
map<string,pair<double,double> > point;

struct maps
{
	string name;
	double area,ratio,x1,x2,y1,y2,cx,cy,dc,dl;
	int level;
	maps(string name,double a,double b,double c,double d):name(name),x1(a),y1(b),x2(c),y2(d)
	{
		double temp;
		if(x1>x2) temp=x1,x1=x2,x2=temp;
		if(y1>y2) temp=y1,y1=y2,y2=temp;
		cx=(x1+x2)/2;
		cy=(y1+y2)/2;
		area=(x2-x1)*(y2-y1);
		ratio=(y2-y1)/(x2-x1)-0.75;
		if(ratio<0) ratio=-ratio;
	}
	bool in(const pair<double,double> &a) const
	{
		//printf("%lf %lf\n",a.first,a.second);
		//printf("%lf %lf %lf %lf\n",x1,x2,y1,y2);
		return x1<=a.first&&a.first<=x2&&y1<=a.second&&a.second<=y2;
	}
};

vector<maps> mapx;

bool cmp1(const double &a,const double &b)
{
	return a>b;
}

bool maincmp(const maps &a,const maps &b)
{
	if(a.level!=b.level) return a.level>b.level;
	if(!equal(a.dc,b.dc)) return a.dc<b.dc;
	if(!equal(a.ratio,b.ratio)) return a.ratio<b.ratio;
	if(!equal(a.dl,b.dl)) return a.dl>b.dl;
	return a.x1<b.x1;
}

void initial()
{
	string temp;
	double x1,x2,y1,y2;
	int level,len=0;
	cin>>temp;
	while(cin>>temp&&temp!="LOCATIONS")
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		mapx.push_back(maps(temp,x1,y1,x2,y2));
		len++;
	}
	while(cin>>temp&&temp!="REQUESTS")
	{
		scanf("%lf%lf",&x1,&y1);
		point[temp]=make_pair(x1,y1);
	}
	while(cin>>temp&&temp!="END")
	{
		scanf("%d",&level);
		if(point.count(temp)==0)
			cout<<temp<<" at detail level "<<level<<" unknown location"<<endl;
		else
		{
			vector<maps> now;
			vector<double> area;
			pair<double,double> nowpoint=point[temp];
			int len1=0,con=0;
			double last=-1.0;
			for(int i=0;i<len;i++)
				if(mapx[i].in(nowpoint))
				{
					len1++;
					mapx[i].dc=(mapx[i].cx-nowpoint.first)*(mapx[i].cx-nowpoint.first)+(mapx[i].cy-nowpoint.second)*(mapx[i].cy-nowpoint.second);
					mapx[i].dl=(mapx[i].x2-nowpoint.first)*(mapx[i].x2-nowpoint.first)+(mapx[i].y2-nowpoint.second)*(mapx[i].y2-nowpoint.second);
					now.push_back(mapx[i]);
					area.push_back(mapx[i].area);
				}
			sort(area.begin(),area.end(),cmp1);
			for(int i=0;i<len1;i++)
				if(!equal(area[i],last))
				{
					con++;
					last=area[i];
					for(int j=0;j<len1;j++)
						if(equal(now[j].area,last))
							now[j].level=con;
				}
			sort(now.begin(),now.end(),maincmp);
			cout<<temp<<" at detail level "<<level<<' ';
			if(now.empty())
				cout<<"no map contains that location"<<endl;
			else if(level>now[0].level)
				cout<<"no map at that detail level; using "<<now[0].name<<endl;
			else
			{
				for(int i=0;i<len1;i++)
				{
					if(level==now[i].level)
					{
						cout<<"using "<<now[i].name<<endl;
						break;
					}
				}	
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	initial();
	return 0;
}