#include <cstdio>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	int n;
	int s[103];
	while(time--){
		
		while(scanf("%d",&n)==1)
		{
			for(int i=n;i>0;i--)
				s[i]=n-i+1;
			if(n&1)
			{
				s[n/2+1]=s[n/2];
				s[n/2]=n/2+1;
				
			}
			for(int i=1;i<=n;i++)
				printf("%d ",s[i]);
			printf("\n");
		}}
	return 0;
}