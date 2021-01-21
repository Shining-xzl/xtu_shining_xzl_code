#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#define all(s0) s0.begin(),s0.end()
#define ins(s0) inserter(s0,s0.begin())
using namespace std;
typedef vector<int> Vector;
unsigned int allnum=0;
map<string,Vector> rough,careful[102];
vector< vector<string> > library;

void process(string &now,int r,int l)
{
	for(int i=0;now[i]!='\0';i++)
	{
		if(now[i]>='A'&&now[i]<='Z')
			now[i]+=32;
		if(now[i]<'a'||now[i]>'z')
			now[i]=' ';
	}
	stringstream temp(now);
	string x;
	while(temp>>x)
	{
		if(careful[r].count(x)==0)
			careful[r][x].push_back(l);
		else if(careful[r][x].back()!=l)
			careful[r][x].push_back(l);
		if(rough.count(x)==0)
			rough[x].push_back(r);
		else if(rough[x].back()!=r)
			rough[x].push_back(r);
	}
}

void print(int x)
{
	int len=library[x].size();
	for(int i=0;i<len;i++)
		cout<<library[x][i]<<endl;
}

void find_x(string &a)
{
	if(rough.count(a)==0)
	{
		printf("Sorry, I found nothing.\n");
		return;
	}
	else
	{
		int len=rough[a].size(),lenx,op,opx;
		for(int i=0;i<len;i++)
		{
			op=rough[a][i];
			lenx=careful[op][a].size();
			for(int j=0;j<lenx;j++)
			{
				opx=careful[op][a][j];
				cout<<library[op][opx]<<endl;
			}
			if(i!=len-1) printf("----------\n");
		}
	}
}

void find_not(string &a)
{
	if(rough[a].size()==allnum)
	{
		printf("Sorry, I found nothing.\n");
		return;
	}
	bool flag=0;
	int i=0,j=0,len=rough[a].size();
	for(i=0;i<allnum;i++)
	{
		if(j>=len||i!=rough[a][j])
		{
			if(flag) printf("----------\n");
			print(i);
			flag=1;
		}
		else if(i==rough[a][j]) j++;
	}
}

void find_ao(string &a,string &order,string &b)
{
	if((rough.count(a)==0||rough.count(b)==0)&&order[0]=='A')
	{
		printf("Sorry, I found nothing.\n");
		return;
	}
	if((rough.count(a)==0&&rough.count(b)==0)&&order[0]=='O')
	{
		printf("Sorry, I found nothing.\n");
		return;
	}
	Vector now,temp;
	if(order[0]=='O')
	{
		if(rough.count(a)==0)
			now=rough[b];
		else if(rough.count(b)==0)
			now=rough[a];
		else set_union(all(rough[a]),all(rough[b]),ins(now));
	}
	else set_intersection(all(rough[a]),all(rough[b]),ins(now));

	if(now.empty())
	{
		printf("Sorry, I found nothing.\n");
		return;
	}
	int lenx,len=now.size(),op;
	for(int i=0;i<len;i++)
	{
		op=now[i];
		temp.clear();
		set_union(all(careful[op][a]),all(careful[op][b]),ins(temp));
		lenx=temp.size();
		for(int j=0;j<lenx;j++)
		{
			cout<<library[op][temp[j]]<<endl;
		}
		if(i!=len-1)
			printf("----------\n");
	}
}

void work()
{
	int n,con;
	string s[4];
	scanf("%d",&n);
	string now;
	getchar();
	while(n--)
	{
		con=0;
		now="";
		getline(cin,now);
		stringstream temp(now);
		while(temp>>s[con]) con++;
		if(con==1) find_x(s[0]);
		else if(con==2) find_not(s[1]);
		else if(con==3) find_ao(s[0],s[1],s[2]);
		printf("==========\n");
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,con=0,xcon=0;
	vector<string> temp;
	string now;
	scanf("%d",&time);
	allnum=time;
	getchar();
	while(time--)
	{
		temp.clear();
		while(1)
		{
			now="";
			getline(cin,now);
			if(now=="**********") break;
			temp.push_back(now);
			process(now,con,xcon);
			xcon++;
		}
		library.push_back(temp);
		con++;
		xcon=0;
	}
	work();
	return 0;
}