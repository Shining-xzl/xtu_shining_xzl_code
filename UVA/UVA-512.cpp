#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int r,c;


int main()
{
	freopen("in.txt","r",stdin);
	int num_order,num_queries;
	int con=0;
	while(scanf("%d%d",&r,&c)==2)
	{
		if(r==c&&c==0) break;
		
		if (con) putchar('\n');
		printf("Spreadsheet #%d\n",++con);
		
		scanf("%d",&num_order);
		while(num_order--) process();

		scanf("%d",&num_queries);
		while(num_queries--) ans();
	}
	return 0;
}