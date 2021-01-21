#include <cstdio>
using namespace std;
char s[203];

int main()
{
	int time,l,len,r;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",&s);
		scanf("%d%d",&l,&len);
		l--;
		r=len+l-1;
	 	while(len--)
		{
			if(s[r]!=s[l]) break;
			l++;
			r--;
		}
		if(len>0) printf("No\n");
		else printf("Yes\n");
		
	}
	return 0;
}
