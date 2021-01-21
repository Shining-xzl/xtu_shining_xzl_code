#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string name[103];
int tim,maxx;

void out_line()
{
	for(int i=1;i<=60;i++)
		printf("-");
	printf("\n");
}

void out(int k,int flag)
{
	if(k>tim) return;
	cout<<name[k];
	int len=maxx-name[k].length();
	if(flag) len-=2;
	while(len--) printf(" ");
}

int main()
{
	int i,j;
	int l,r;
	while(scanf("%d",&tim)==1)
	{
		maxx=0;
		for(i=1;i<=tim;i++)
		{
			cin>>name[i];
			if(name[i].length()>maxx) 
				maxx=name[i].length();
		}	
		out_line();
		sort(name+1,name+tim+1);
		l=(60-maxx)/(maxx+2)+1;
		r=tim/l;
		if(l*r<tim) r++;
		maxx+=2;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=l;j++)
			{
				out((j-1)*r+i,j==l ? 1:0);
			}
			printf("\n");
		}
	}
	return 0;
 } 
