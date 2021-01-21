#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct information
{
	int id;
	int size,price;
	bool operator < (const information &now) const
	{
		return (price!=now.price) ? (price<now.price) : (id>now.id);
	}
	bool operator > (const information &now) const
	{
		return (price!=now.price) ? (price>now.price) : (id>now.id);
	}
};

struct order
{
	string k;
	int a,b,id;
}p[10003]; 
int n;

map<int,int> buyp,sellp;

priority_queue<information,vector<information>,less<information> > buy;
priority_queue<information,vector<information>,greater<information> > sell;

void clear()
{
	buyp.clear();
	sellp.clear();
	while(!buy.empty()) buy.pop();
	while(!sell.empty()) sell.pop();
	information temp;
	temp.id=10002;
	temp.price=99999;
	temp.size=0;
	sell.push(temp);
	sellp[99999]=0;
	temp.id=10002;
	temp.price=0;
	temp.size=0;
	buy.push(temp);
	buyp[0]=0;
	p[10002].a=1;
}

void x_clear()
{
	while(p[buy.top().id].a==0) buy.pop();
	while(p[sell.top().id].a==0) sell.pop();
}

void process(char o)
{
	x_clear();
	information a,b;
	int Min;
	while(buy.top().price>=sell.top().price)
	{
		if(buy.size()==1||sell.size()==1) break;
		a=buy.top();
		buy.pop();
		b=sell.top();
		sell.pop();
		if(a.size<b.size) Min=a.size;
		else Min=b.size;
		a.size-=Min;
		b.size-=Min;
		p[a.id].a-=Min;
		p[b.id].a-=Min;
		buyp[a.price]-=Min;
		sellp[b.price]-=Min;
		printf("TRADE %d ",Min);
		if(o=='B')
			printf("%d\n",b.price);
		else printf("%d\n",a.price);
		if(a.size>0) buy.push(a);
		if(b.size>0) sell.push(b);
		x_clear();
	}
	printf("QUOTE %d %d - %d %d\n",buyp[buy.top().price],buy.top().price,sellp[sell.top().price],sell.top().price);
}

int main()
{
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int con=0;
	while(scanf("%d",&n)==1)
	{
		if(con++) printf("\n");
		clear();
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].k;
			p[i].id=i;
			if(p[i].k[0]=='C') 
			{
				cin>>p[i].a;
				if(p[p[i].a].a!=0)
				{
					if(p[p[i].a].k[0]=='B')
						buyp[p[p[i].a].b]-=p[p[i].a].a;
					else sellp[p[p[i].a].b]-=p[p[i].a].a;
					p[p[i].a].a=0;
				}
			}
			else 
			{
				cin>>p[i].a>>p[i].b;
				if(p[i].k[0]=='B') 
				{
					buy.push(information{i,p[i].a,p[i].b});
					if(buyp.count(p[i].b)==0)
						buyp[p[i].b]=p[i].a;
					else buyp[p[i].b]+=p[i].a;
				}
				else 
				{
					sell.push(information{i,p[i].a,p[i].b});
					if(sellp.count(p[i].b)==0)
						sellp[p[i].b]=p[i].a;
					else sellp[p[i].b]+=p[i].a;
				}
			}
			process(p[i].k[0]);
		}
	}	
	return 0;
}