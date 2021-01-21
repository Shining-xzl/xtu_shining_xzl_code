#include <cstdio>
#include <cstring>
using namespace std;
char s[1003];
int len;

inline bool right(int a,int l)
{
	int k=l;
	while(k--)
	{
		if(s[a]!=s[a+l]) return 0;
		a++;
	}
	return 1;
}

int main()
{
	int time,l,i,j,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		len=strlen(s);
		l=len>>1;
		ans=0;
		for(i=l;i>=0;i--)
		{
			for(j=0;j+i<len;j++)
				if(right(j,i))
				{
					ans=i;
					break;
				}
			if(ans) break;
		}
		printf("%d\n",ans<<1);
			
	}
	return 0;
}
