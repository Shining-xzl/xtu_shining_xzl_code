#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
map<char,string> transfor;
vector<string> library,pc;
int ind[1003];

void process(string &x)
{
	string temp="";
	int len=x.length();
	for(int i=0;i<len;i++)
		temp+=transfor[x[i]];
	x=temp;
}

int cmp(string a,string b)
{
	int len,max;
	if(a.length()>b.length())
		len=b.length(),max=a.length();
	else len=a.length(),max=b.length();
	for(int i=0;i<len;i++)
		if(a[i]!=b[i]) return 100;
	return max-len;
}

void search(string &x)
{
	int len=pc.size(),con=0;
	for(int i=0;i<len;i++)
	{
		if(x==library[i])
		{
			con++;
			if(con==1)
				cout<<pc[i];
		}
	}
	if(con>1) printf("!\n");
	else if(con==1) printf("\n");
	else
	{
		int diff=100,now;
		string temp;
		for(int i=0;i<len;i++)
		{
			now=cmp(library[i],x);
			if(now<diff) diff=now,temp=pc[i];
		}
		cout<<temp<<'?'<<endl;
	}
}

int	main()
{
	string pre,now;
	while(cin>>pre)
	{
		if(pre=="*") break;
		cin>>now;
		transfor[pre[0]]=now;	
			
	}
	while(cin>>now)
	{
		if(now=="*") break;
		pc.push_back(now);
		process(now);
		library.push_back(now);
	}
	while(cin>>now)
	{
		if(now=="*") break;
		search(now);
	}
	return 0;
}