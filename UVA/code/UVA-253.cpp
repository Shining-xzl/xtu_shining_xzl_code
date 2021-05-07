#include <cstdio>
#include <string>
using namespace std;

char s[13];
int now[9]; 

bool eq(int a,int c,int b,int d,int e,int f)
{
	if(a==d&&b==e&&c==f)
		return true;
	if(a==e&&b==f&&c==d)
		return true;
	if(a==f&&b==d&&c==e)
		return true;
	else return false;
}
bool check()
{
	now[0]=s[0]*10+s[5];
	now[1]=s[1]*10+s[4];
	now[2]=s[2]*10+s[3];
	now[3]=s[3]*10+s[2];
	now[4]=s[4]*10+s[1];
	now[5]=s[5]*10+s[0];

	now[6]=s[6]*10+s[11];
	now[7]=s[7]*10+s[10];
	now[8]=s[8]*10+s[9];

	if(eq(now[6],now[7],now[8],now[0],now[2],now[1]))
		return true;
	if(eq(now[6],now[7],now[8],now[0],now[4],now[2]))
		return true;
	if(eq(now[6],now[7],now[8],now[0],now[3],now[4]))
		return true;
	if(eq(now[6],now[7],now[8],now[0],now[1],now[3]))
		return true;
	if(eq(now[6],now[7],now[8],now[5],now[1],now[2]))
		return true;
	if(eq(now[6],now[7],now[8],now[5],now[2],now[4]))
		return true;
	if(eq(now[6],now[7],now[8],now[5],now[4],now[3]))
		return true;
	if(eq(now[6],now[7],now[8],now[5],now[3],now[1]))
		return true;
	return false;
}

int main()
{
	while(scanf("%s",s)==1)
		if(check())
			printf("TRUE\n");
		else printf("FALSE\n");
	return 0;
}