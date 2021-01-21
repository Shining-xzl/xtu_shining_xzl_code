#include <cstdio>
#include <cstring>
using namespace std;

char s[82];
int n;

bool right(short k,short len)
{
	for(short i=k;i<len;i++)
		if(s[i%k]!=s[i]) return false;
	return true;
}

void initial()
{
	short len,i;
	scanf("%s",&s);
	len=strlen(s);
	for(i=1;i<=len;i++)
	{
		if(len%i) continue;
		if(right(i,len))
		{
			printf("%d\n",i);
			if(n) printf("\n");
			return;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
