#include <stdio.h>
#include <cstring>
#include <math.h>
using namespace std;

char a[37],b[37];
int an,bn;

int turn(char s[],int n)
{
	int l=0,len,i,k=1,ans=0,p;
	len=strlen(s);
	if(s[0]=='-') l++;
	for(i=len-1;i>=l;i--)
	{
		if(s[i]>='0'&&s[i]<='9') p=s[i]-48;
		else if(s[i]>='A'&&s[i]<='Z') p=s[i]-55;
		else if(s[i]>='a'&&s[i]<='z') p=s[i]-61;
		ans+=k*p;
		k*=n;
	}
	if(s[0]=='-') ans=-ans;
	return ans;
}

int main()
{
	int time,A,B;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",&a);
		scanf("%d",&an);
		scanf("%s",&b);
		scanf("%d",&bn);
		A=turn(a,an);
		B=turn(b,bn);
		printf("%d\n",A+B);
	}
	return 0;
}
