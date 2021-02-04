#include <cstdio>
using namespace std;

void initial()
{
	int a,d,ans=0;
	scanf("%d%d",&a,&d);
	if(a<d) ans=d-a;
	else if((a-d)&1) ans=1;
	else ans=0;
	printf("%d\n",ans);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
