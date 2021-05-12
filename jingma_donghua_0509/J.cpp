/*
sg表 找规律，循环节
*/
#include <cstdio>
#include <cstring>
using namespace std;

bool vis[1003];
int sg[403];

int get_sg(int x)
{
	memset(vis, 0, sizeof(vis));
	for (int len = 1; len <= 4; ++len)
		for (int start = 1; start <= x-len+1; start++)
			vis[sg[start-1]^sg[x-len-start+1]] = 1;
	for (int i = 0; i < 1003; ++i)
		if(!vis[i]) return i;
}
int stand[] = {5,16,17,3,2,8,9,14,15,5,4,3,2,16,17,4,5,15,14,9,8,2,3,4}; // start in 149 

int main()
{
	sg[0] = 0;
	for (int i = 1; i < 400; ++i)
		sg[i] = get_sg(i);
	int n;
	int ans,temp,x;
	while(scanf("%d", &n) == 1)
	{
		ans = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&x);
			if(x > 149)
			{
				x -= 149;
				x %= 24;
				temp = stand[x];
			}
			else temp = sg[x];
			ans ^= temp;
		}
		if(ans == 0) printf("lets see who is real evil genius\n");
		else printf("Emo:?\n");
	}
	return 0;
}