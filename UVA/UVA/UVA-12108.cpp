#include <cstdio>
#include <set>
#include <vector>
using namespace std;
struct student
{
	int a,b,now;
	bool operator < (const student &x) const
	{
		return a*100+b*10+now<x.a*100+x.b*10+x.now;
	}
};
typedef vector<student> Student;
int n,con=0;

int work()
{
	student temp;
	Student _class;
	set<Student> home;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&temp.a,&temp.b,&temp.now);
		// printf("%d %d %d\n",temp.a,temp.b,temp.now );
		_class.push_back(temp);
	}
	int time=0,cona,conb;
	home.insert(_class);
	while(1)
	{
		time++;
		cona=0;
		conb=0;
		for(int i=0;i<n;i++)
		{
			if(_class[i].now>_class[i].a) conb++;
			else cona++;
		}
		if(cona==n) return time;
		for(int i=0;i<n;i++)
		{
			if(_class[i].now==_class[i].a)
			{
				if(conb>cona) _class[i].now++;
				else _class[i].now=1;
			}
			else _class[i].now++;
			if(_class[i].now>_class[i].a+_class[i].b) 
				_class[i].now=1;
			//printf("%d ",_class[i].now);
		}
		if( home.count(_class)==1 ) return -1;
		else home.insert(_class);
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d",&n)==1&&n!=0)
		printf("Case %d: %d\n",++con,work());
	return 0;
}
