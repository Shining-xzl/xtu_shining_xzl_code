#include <cstdio>
#include <map>
using namespace std;

map<int,int> p;

void process(int val,int pos)
{
	// printf("%d %d\n",pos,val);
	if(val==-1) return;
	if(p.count(pos)==0)
		p[pos]=val;
	else p[pos]+=val;
	int l,r;
	scanf("%d",&l);
	process(l,pos-1);
	scanf("%d",&r);
	process(r,pos+1);
}

int main()
{
	int val,Cas=0;
	while(scanf("%d",&val)==1&&val!=-1)
	{
		p.clear();
		process(val,0);
		map<int,int>::iterator it=p.begin();
		printf("Case %d:\n",++Cas);
		printf("%d",it->second);
		for(it=++p.begin();it!=p.end();++it)
			printf(" %d",it->second);
		printf("\n\n");
	}
	return 0;
} 
