#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

map<string,string> dictionary;
map<string,string> now;
vector<string> v;

void process(char s[],map<string,string> &now)
{
	string a="",b="",temp;
	bool flag=1;
	int i=1;
	while(s[i]!='}')
	{
		if(s[i]==',')
		{
			if(a[0]>='0'&&a[0]<='9')
			{
				temp=a;
				a=b;
				b=temp;
			}
			now[a]=b;
			// cout<<a<<' '<<b<<endl;
			a="";
			b="";
			flag=1;
		}
		else if(s[i]==':')
			flag=0;
		else if(flag)
			a+=s[i];
		else b+=s[i];
		i++;
	}
	if(a=="") return;
	if(a[0]>='0'&&a[0]<='9')
	{
		temp=a;
		a=b;
		b=temp;
	}
	now[a]=b;
	// cout<<a<<' '<<b<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int time,con,op;
	char s[103];
	map<string,string>::iterator it;
	string temp;
	scanf("%d",&time);
	while(time--)
	{
		dictionary.clear();
		now.clear();
		scanf("%s",s);
		process(s,dictionary);
		scanf("%s",s);
		process(s,now);
		con=0;
		for(it=now.begin();it!=now.end();it++)
		{
			temp=it->first;
			//cout<<temp<<endl;
			if(dictionary.count(temp)==0)
			{
				con++;
				v.push_back(temp);
			}
		}
		op=con;
		if(con)
		{
			sort(v.begin(),v.end());
			cout<<'+'<<v[0];
			for(int i=1;i<con;i++)
				cout<<','<<v[i];
			cout<<endl;
		}
		v.clear();
		con=0;
		for(it=dictionary.begin();it!=dictionary.end();it++)
		{
			temp=it->first;
			//cout<<temp<<endl;
			if(now.count(temp)==0)
			{
				con++;
				v.push_back(temp);
			}
		}
		op+=con;
		if(con)
		{
			sort(v.begin(),v.end());
			cout<<'-'<<v[0];
			for(int i=1;i<con;i++)
				cout<<','<<v[i];
			cout<<endl;
		}
		v.clear();
		con=0;
		for(it=now.begin();it!=now.end();it++)
		{
			temp=it->first;
			//cout<<temp<<endl;
			if(dictionary.count(temp)&&dictionary[temp]!=now[temp])
			{
				con++;
				v.push_back(temp);
			}
		}
		op+=con;
		if(con)
		{
			sort(v.begin(),v.end());
			cout<<'*'<<v[0];
			for(int i=1;i<con;i++)
				cout<<','<<v[i];
			cout<<endl;
		}
		v.clear();
		if(op==0)
			printf("No changes\n");
		printf("\n");
	}
	return 0;
}