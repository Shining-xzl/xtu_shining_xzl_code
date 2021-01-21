#include <cstdio>
using namespace std;
char s[11];

int s1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int s2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int time,a,b,c,i;
	int *k;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",&s);
		a=(s[0]-48)*1000+(s[1]-48)*100+(s[2]-48)*10+s[3]-48;
		b=(s[5]-48)*10+s[6]-48;
		c=(s[8]-48)*10+s[9]-48;
		if((a%4==0)&&(a%100!=0)||(a%400==0)) k=s2;
		else k=s1;
		for(i=1;i<b;i++)
			c+=k[i];
		printf("%d\n",c);
			
	}
	
	return 0;
}
