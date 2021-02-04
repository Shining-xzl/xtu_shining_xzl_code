#include <cstdio>
using namespace std;
unsigned char s[134];
unsigned char a[120];
unsigned char b[120];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%s",s);
	int aop=0,bop=0;
	for(int i=0;i<32;i++)
	{
		if(s[i]>='0'&&s[i]<='9') b[++bop]=s[i]-'0';
		else a[++aop]=s[i];
	}
	for(int i=1;i<=16;i++)
	{
//		printf("%c %d",a[i],b[i]);
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]+=b[i];
			if(a[i]>'z') a[i]-=57; 
		} 
		else if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]+=b[i];
			if(a[i]>'Z') a[i]+=7;
		}
//		printf("->%c\n",a[i]);
	}
	for(int i=0;i<4;i++)
	{
		printf("%c%c%c%c",a[i*4+4],a[i*4+3],a[i*4+2],a[i*4+1]);
	}
	return 0;
 } 
