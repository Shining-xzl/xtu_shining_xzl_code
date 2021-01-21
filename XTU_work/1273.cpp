#include <cstdio>
using namespace std;
const int T=100002;
int s[T],n;
//每个数两次操作，合并相当与三种操作只能进行一次 
int main()
{
	int time,a,b,c,d;
	bool flag; 
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
        a=-1;
        b=-1;
        c=-1;
        d=-1;
        flag=1;
        while(n--)
        {
            scanf("%d",&s[n]);
            if(s[n]==a||s[n]==b||s[n]==c||s[n]==d) continue;
            if(a==-1) a=s[n];
            else if(b==-1) b=s[n];
            else if(c==-1) c=s[n];
            else if(d==-1) d=s[n];
            else flag=0;
        }
        if(flag) 
		{
			if(d==-1)
			  printf("Yes\n");
			else
			{
				if(a>b) n=b,b=a,a=n;
				if(a>c) n=c,c=a,a=n;
				if(a>d) n=d,d=a,a=n;
				if(b>c) n=c,c=b,b=n;
				if(b>d) n=d,d=b,b=n;
				if(c>d) n=d,d=c,c=n;
				if(d-b==c-a) 
					printf("Yes\n");
				else printf("No\n");
			}
		}
        else printf("No\n");
	}
	return 0;
} 
