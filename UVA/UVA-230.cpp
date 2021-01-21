#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct book
{
	string name,anthor;
	bool operator < (const book &a) const
	{
		if(anthor==a.anthor)
		{
			return name<a.name;
		}
		else return anthor<a.anthor;
	}
};

set<book> library,indexs,table;

void initial()
{
	string name,anthor,temp;
	book now;
	int pos;
	while(getline(cin,temp)&&temp!="END")
	{
		pos=temp.find('\"',1);
		now.name=temp.substr(0,pos+1);
		now.anthor=temp.substr(pos+5);
		library.insert(now);
	}
	indexs=library;
/*	set<book>::iterator it;
	for(it=library.begin();it!=library.end();it++)
	{
		now=*it;
		cout<<now.name<<' '<<now.anthor<<endl;
	}
*/
}

book find_x(string &name)
{
	set<book>::iterator it;
	book temp;
	for(it=indexs.begin();it!=indexs.end();it++)
	{
		temp=*it;
		if(temp.name==name) break;
	}
	return temp;
}

void work()
{
	string temp;
	string order,name;
	book temp_book;
	int pos;
	pair< set<book>::iterator,bool > pa;
	set<book>::iterator it;

	while(getline(cin,temp)&&temp!="END")
	{
		if(temp=="SHELVE")
		{
			for(it=table.begin();it!=table.end();it++)
			{
				temp_book=*it;
				pa=library.insert(temp_book);
				cout<<"Put "<<temp_book.name;
				if(pa.first==library.begin())
					cout<<" first"<<endl;
				else 
				{
					temp_book=*(--pa.first);
					cout<<" after "<<temp_book.name<<endl;
				}
			}
			cout<<"END"<<endl;
			table.clear();
		}
		else
		{
			pos=temp.find(' ');
			order=temp.substr(0,pos);
			name=temp.substr(pos+1);
			temp_book=find_x(name);
			// cout<<order<<' '<<name<<endl;
			if(order[0]=='B')
				library.erase(temp_book);
			else table.insert(temp_book);
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	initial();
	work();
	return 0;
}