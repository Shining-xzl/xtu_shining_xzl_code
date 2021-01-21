#include <cstdio>
#include <cstring>
using namespace std;
short S[1002],a[1002],num[10],temp[10];
int n,N;

void initial()
{
	if(n==0) return;
	printf("Game %d:\n",++N);
	memset(num,0,sizeof(num));
	short i,A,B;
	for(i=1;i<=n;i++)
		scanf("%d",&S[i]),num[S[i]]++;
	while(scanf("%d",&a[1])==1)
	{
		for(i=2;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[1]==0) return;
		A=B=0;
		for(i=1;i<=9;i++)
			temp[i]=num[i];
		for(i=1;i<=n;i++)
			if(a[i]==S[i]) 
				A++,temp[a[i]]--;
		for(i=1;i<=n;i++)
			if(a[i]!=S[i]&&temp[a[i]])
				B++,temp[a[i]]--;
		printf("    (%d,%d)\n",A,B);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)==1) initial();
	return 0;
}
