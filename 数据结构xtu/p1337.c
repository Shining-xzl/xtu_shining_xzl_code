#include <stdio.h>
int n,num = 0, l = 1;
int q[1003],w[1003],vis[1003];

int main()
{
	char s[13];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		if (s[0] == 'i')
		{
			scanf("%d %d", &q[l], &w[l]);
			l++;
			++num;
		}
		else
		{
			if (num == 0) printf("none\n");
			else
			{
				int i,f = -1;
				--num;
				for (i = 1; i < l; ++i)
				{
					if (vis[i] == 0)
					{
						if (f == -1) f = i;
						else if (w[i] > w[f]) f = i;
					}
				}
				printf("%d %d\n",q[f],w[f]);
				vis[f] = 1;
			}
		}
	}
	return 0;
 } 
