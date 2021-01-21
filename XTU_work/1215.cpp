#include <cstdio>
#include <cstring>
using namespace std;
char s[12];
int a[12],b[12];

void get(int a[])
{
	int i;
	a[0]=strlen(s);
	for(i=1;i<=a[0];i++)
		a[i]=s[a[0]-i]-48;
}

int main()
{
	int time,len,i;
	scanf("%d",&time);
	while(time--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s",s);
		get(a);
		scanf("%s",s);
		get(b);
		if(a[0]>b[0]) len=a[0];
		else len=b[0];
		for(i=1;i<=len;i++)
			a[i]+=b[i];
		for(i=1;i<=len;i++)
			if(a[i]>9) a[i]-=10;
		while(a[len]==0) len--;
		if(len==0) printf("0\n");
		else
		{
			for(i=len;i>0;i--)
				printf("%d",a[i]);
			printf("\n");
		}
	}
	return 0;
}
