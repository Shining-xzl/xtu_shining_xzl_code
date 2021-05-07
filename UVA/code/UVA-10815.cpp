#include <cstdio>
#include <string>
#include <set>
#include <iostream>
using namespace std;

set<string> home;

int main()
{
	freopen("in.txt","r",stdin);
	string x="";
	char a;
	do
	{
		a=getchar();
		while((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
		{
			if(a<='Z')	a+=32;
			x+=a;
			a=getchar();
		}
		if(x!="")
			home.insert(x),x="";
	}while(a!=EOF);
	set<string>::iterator it;
	for(it=home.begin();it!=home.end();it++)
		cout<<*it<<endl;
	return 0;
}