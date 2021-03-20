#include <cstdio>
using namespace std;

bool flag;
int solve()
{
	int w1,c1,w2,c2;
	scanf("%d%d%d%d",&w1,&c1,&w2,&c2);
	if(w1==0) w1=solve();
	if(w2==0) w2=solve();
	if(w1*c1!=w2*c2) flag=0;
	return w1+w2;
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		flag=1;
		solve();
		if(flag) printf("YES\n");
		else printf("NO\n");
		if(time) printf("\n");
	}
	return 0;
} 
