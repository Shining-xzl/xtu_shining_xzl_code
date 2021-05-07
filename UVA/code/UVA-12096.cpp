#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
typedef set<int> SET;

map<SET,int> ID;
vector<SET> library;
int id_num=0;

int get_ID(SET &x)
{
	if(ID.count(x)==0)
	{
		ID[x]=id_num++;
		library.push_back(x);
	}	
	return ID[x];
}

void core()
{
	int time;
	char instruction[10];
	scanf("%d",&time);
	stack<int> home;
	SET empty,a,b,temp;
	while(time--)
	{
		scanf("%s",instruction);
		switch(instruction[0])
		{
			case 'P': home.push(get_ID(empty));
					  break;
			case 'D': home.push(home.top());
					  break;
			case 'U': a=library[home.top()];
					  home.pop();
					  b=library[home.top()];
					  home.pop();
					  set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(temp,temp.begin()));
					  home.push(get_ID(temp));
					  temp.clear();
					  break;
			case 'I': a=library[home.top()];
					  home.pop();
					  b=library[home.top()];
					  home.pop();
					  set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(temp,temp.begin()));
					  home.push(get_ID(temp));
					  temp.clear();
					  break;
			case 'A': a=library[home.top()];
					  home.pop();
					  b=library[home.top()];
					  home.pop();
					  b.insert(get_ID(a));
					  home.push(get_ID(b));
					  break;
		}
		printf("%u\n",library[home.top()].size());
	}
	printf("***\n");
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--) core();
	return 0;
}