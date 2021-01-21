#include <cstdio>
#include <cstring>
using namespace std;
bool k[12];

bool ok(int a,int b)
{
	if(k[b]) return 0;
	int temp;
	if(a>b) 
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a==1)
	{
		if(b==3&&!k[2]) return 0;
		if(b==7&&!k[4]) return 0;
		if(b==9&&!k[5]) return 0;
	}
	if(a==3)
	{
		if(b==7&&!k[5]) return 0;
		if(b==9&&!k[6]) return 0;
	}
	if(a==2&&b==8&&!k[5]) return 0;
	if(a==4&&b==6&&!k[5]) return 0;
	if(a==7&&b==9&&!k[8]) return 0;
	return 1;
}

int main()
{
	int time,i,a,b;
	bool flag=1;
	char s[12];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		a=0;
		flag=1;
		memset(k,0,sizeof(k));
		for(i=0;s[i]!='\0';i++)
		{
			b=s[i]-'0';
			if(ok(a,b))
			{
				k[b]=1;
				a=b;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
