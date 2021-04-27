#include <stdio.h>
int f[6][6];

int check(int i,int j)
{
	int p;
	for(p = 0; p < 5; ++p)
		if(f[i][j] < f[i][p]) return 0;
	for(p = 0; p < 5; ++p)
		if(f[i][j] > f[p][j]) return 0;
	return 1;
}

int main()
{
	int i,j;
	for(i = 0; i < 5; ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			scanf("%d", &f[i][j]);
		}
	}
	for(i = 0; i < 5; ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			if(check(i,j))
			{
				printf("%d %d %d\n",i+1,j+1,f[i][j]);
				return 0;
			}
		}
	}
	printf("not found\n");
	return 0;
}