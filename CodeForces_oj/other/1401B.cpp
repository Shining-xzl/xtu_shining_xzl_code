#include <cstdio>
using namespace std;

void initial()
{
	int a0,a1,a2,b0,b1,b2,ans;
	scanf("%d%d%d%d%d%d",&a0,&a1,&a2,&b0,&b1,&b2);
	if(a2>=b1) ans=b1<<1,a2-=b1,b1=0;
	else ans=a2<<1,b1-=a2,a2=0;
	if(b2>a0+a2) ans-=((b2-a0-a2)<<1);
	printf("%d\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
