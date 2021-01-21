#include <cstdio>
#include <cstring>
using namespace std;
char s[204];
int n;
int stack[203],len;

void initial()
{
	int r,l,temp;
	len=0;
	gets(s);
	r=strlen(s);
	l=0;
	while(l<r)
	{
		if(s[l]>='0'&&s[l]<='9')
		{
			temp=0;
			while(s[l]>='0'&&s[l]<='9'&&l<r)
				temp=temp*10+s[l]-'0',l++;
			stack[++len]=temp;
		}
		else if(s[l]=='+') temp=stack[len-1]+stack[len],stack[--len]=temp;
		else if(s[l]=='-') temp=stack[len-1]-stack[len],stack[--len]=temp;
		else if(s[l]=='*') temp=stack[len-1]*stack[len],stack[--len]=temp;
		else if(s[l]=='/') temp=stack[len-1]/stack[len],stack[--len]=temp;
		else if(s[l]=='%') temp=stack[len-1]%stack[len],stack[--len]=temp;
		l++;
	}
	printf("%d\n",stack[len]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	gets(s);
	while(n--) initial();
	return 0;
}
