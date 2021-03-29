#include <cstdio>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

map< string, int > ID;
vector< string > rID;
vector< int > inset;
map< int,vector< int > > before, after;
int op;
int status[10003];

void initial()
{
	memset(status, 0, sizeof(status));
	ID.clear();
	rID.clear();
	before.clear();
	after.clear();
	op = 0;
}

int get_id(string &x)
{
	if(ID.find(x) == ID.end())
	{
		ID[x] = op++;
		rID.push_back(x);
	}
	return ID[x];
}

void show()
{
	vector< int >::iterator it;
	for (it = inset.begin(); it != inset.end(); ++it)
		cout << "   " << rID[*it] << endl;
}

void install(int x,bool top)
{
	if(status[x] != 0 && top) cout << "   " << rID[x] << " is already installed." << endl;
	else if(status[x] == 0)
	{
		vector< int >::iterator it;
		for (it = before[x].begin(); it != before[x].end(); ++it) 
			install(*it, false);
		cout << "   Installing " << rID[x] << endl;
        status[x] = (top ? 1 : 2);
        inset.push_back(x);
	}
}

bool isneed(int x)
{
	vector< int >::iterator it;
	for (it = after[x].begin(); it != after[x].end(); ++it) 
		if(status[*it] != 0) return true;
	return false;
}

void remove(int x,bool top)
{
	if(status[x] == 0 && top ) cout << "   " << rID[x] << " is not installed." << endl;
	else if(status[x] !=0 && top && isneed(x)) 
		cout << "   " << rID[x] << " is still needed." << endl;
	else if(status[x] !=0 && !isneed(x))
	{
		cout << "   Removing " << rID[x] << endl;
		status[x] = 0;
		inset.erase(find(inset.begin(),inset.end(),x));
		vector< int >::iterator it;
		for (it = before[x].begin(); it != before[x].end(); ++it) 
			if(status[*it] == 2)
				remove(*it, false);
	}
}

int main()
{
	string now,cmd;
	stringstream all;
	int a,b;
	while(getline(cin,now))
	{
		cout << now << endl;
		if(now == "END")
		{
			initial();
			continue;
		}
		all.clear(); all.str(now);
		all >> cmd;
		if(cmd == "LIST")
			show();
		else if(cmd == "REMOVE")
		{
			all >> now;
			a = get_id(now);
			remove(a,true);
		}
		else if(cmd == "INSTALL")
		{
			all >> now;
			a = get_id(now);
			install(a,true);
		}
		else if(cmd == "DEPEND")
		{
			all >> now;
			a = get_id(now);
			while(all >> now)
			{
				b = get_id(now);
				before[a].push_back(b);
				after[b].push_back(a);
			}
		}
	}
	return 0;
}