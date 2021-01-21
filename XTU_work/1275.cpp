#include <cstdio>
#include <cstring>
using namespace std;

bool t[7][13]; 
int n,m;
int ans[103],ax[103],bx[103],len;

bool ok(int d,int a)
{
	int i,b=a+m-1;
	if(a<=4&&b>4) return 0;
	if(a<=8&&b>8) return 0;
	if(b>11) return 0;
	for(i=a;i<=b;i++)
		if(t[d][i]==1) return 0;
	return 1;
}

int main()
{
	int time,i;
	char s[5];
	int k,a,b;
	scanf("%d",&time);
	while(time--)
	{
		memset(t,0,sizeof(t));
		scanf("%d%d",&n,&m);
		while(n--)
		{
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='M') k=1;
			else if(s[0]=='T'&&s[1]=='u') k=2;
			else if(s[0]=='W') k=3;
			else if(s[0]=='T'&&s[1]=='h') k=4;
			else if(s[0]=='F') k=5;
			else continue;
			for(i=a;i<=b;i++)
				t[k][i]=1;
		}
		len=0;
		for(i=1;i<=5;i++)
			for(a=1;a<=11;a++)
				if(ok(i,a))
				{
					len++;
					ans[len]=i;
					ax[len]=a;
					bx[len]=a+m-1;
				}
		printf("%d\n",len);
		for(i=1;i<=len;i++)
		{
			if(ans[i]==1) printf("Mon");
			else if(ans[i]==2) printf("Tue");
			else if(ans[i]==3) printf("Wen");
			else if(ans[i]==4) printf("Thur");
			else if(ans[i]==5) printf("Fri");
			printf(" %d %d\n",ax[i],bx[i]);
		}
	}
	return 0;
} 
