#include <stdio.h>
int n,m;
struct SB
{
	int id,x,y,z,sum;
}s[1003];
int vis[1003];

int check(struct SB a,struct SB b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	if (a.x != b.x) return a.x > b.x;
	if (a.y != b.y) return a.y > b.y;
	if (a.z != b.z) return a.z > b.z;
	return a.id < b.id;
}

int main()
{
	int i,j;
	scanf("%d %d", &n,&m);
	for (i = 1; i <= n; ++i)
	{
		s[i].id = i;
		scanf("%d %d %d", &s[i].x,&s[i].y,&s[i].z);
		s[i].sum = s[i].x + s[i].y +s[i].z;
	}
	int f;
	for (i = 1; i <= m; ++i)
	{
		f = -1;
		for (j = 1; j <= n; ++j)
		{
			if (vis[j] == 0)
			{
				if (f == -1) f = j;
				else if (check(s[j],s[f]) == 1)
					f = j;
			}
		}
		printf ("%d ",f);
		vis[f] = 1;
	}	 
	return 0;
}
