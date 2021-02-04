#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

map<string,set<string> > home;

void initial()
{
	string temp,addess;
	int n;
	while(cin>>temp)
	{
		if(temp=="*") break;
		if(temp=="MTA")
		{
			cin>>addess>>n;
			while(n--)
			{
				cin>>temp;
				home[addess].insert(temp);
			}
		}
	}
}

void work()
{
	getchar();
	string temp,tempuser,tempadd,suers,sadd;
	map<string,vector<string> > box;
	vector<string> ebox,data;
	set<string> name;
	while(getline(cin,temp))
	{
		if(temp=="*") break;
		box.clear();
		ebox.clear();
		for(int i=0;temp[i]!='\0';i++)
			if(temp[i]=='@') temp[i]=' ';
		stringstream uesr(temp);
		uesr >> suers >> sadd;
		//cout<<suers<<' '<<sadd<<endl;
		while(uesr>>tempuser>>tempadd)
		{
			//cout<<tempuser<<'@'<<tempadd<<endl;
			if(box.count(tempadd)==0) ebox.push_back(tempadd);
			box[tempadd].push_back(tempuser);
		}
		getline(cin,temp);
		data.clear();
		while(getline(cin,temp))
		{
			if(temp=="*") break;
			data.push_back("     "+temp);
		}
		int len=ebox.size();
		for(int i=0;i<len;i++)
		{
			cout<<"Connection between "<<sadd<<" and "<<ebox[i]<<endl;
			cout<<"     HELO "<<sadd<<endl<<"     250"<<endl;
			cout<<"     MAIL FROM:<"<<suers+'@'+sadd<<">\n     250"<<endl;
			int con=0,xlen=box[ebox[i]].size();
			name.clear();
			for(int j=0;j<xlen;j++)
			{
				if(name.count(box[ebox[i]][j])) continue;
				cout<<"     RCPT TO:<"<<box[ebox[i]][j]+'@'+ebox[i]<<">"<<endl;
				name.insert(box[ebox[i]][j]);
				if(home[ebox[i]].find(box[ebox[i]][j])!=home[ebox[i]].end())
				{
					cout<<"     250"<<endl;
					con++;
				}
				else cout<<"     550"<<endl;
			}
			if(con!=0)
			{
				cout<<"     DATA\n     354"<<endl;
				xlen=data.size();
				for(int j=0;j<xlen;j++)
					cout<<data[j]<<endl;
				cout<<"     .\n     250"<<endl;
			}
			cout<<"     QUIT\n     221"<<endl;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	initial();
	work();
	return 0;
}