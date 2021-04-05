#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int lim = 103;
int flag = 0;
int n,u,v;
int pos[lim];

int main()
{
	int time,ans;
	scanf("%d",&time);
	while(time--)
	{
		flag = 0;
		scanf("%d %d %d",&n,&u,&v);
		for (int i = 0; i < n; ++i)
			scanf("%d",&pos[i]);
		for (int i = 1; i < n; ++i)
		{
			if(flag == 0 && pos[i] != pos[i-1])
				flag = 1;
			if(abs(pos[i] - pos[i-1]) > 1)
				flag = 2;
		}
		if(flag == 2)
			ans = 0;
		else if(flag == 0)
			ans = min(v+v,u+v);
		else ans = min(u,v);
		printf("%d\n", ans);
	}	
	return 0;
}