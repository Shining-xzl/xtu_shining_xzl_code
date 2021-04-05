#include <cstdio>
using namespace std;
int N,Q;
int c[27];
int k[27];

bool ask(int x,int y)
{
	printf("? %c %c\n", x+'A',y+'A');
	fflush(stdout);
	char s;
	scanf(" %c", &s);
	return s == '<';
}

void sort(int l,int r)
{
	if(l == r) return;
	int mid = (l+r) >> 1;
	sort(l,mid);
	sort(mid + 1,r);
	int a = l,b = mid + 1,i = l;
	while(a <= mid || b <= r)
	{
		if(a > mid) k[i++] = c[b++];
		else if(b > r) k[i++] = c[a++];
		else
		{
			if(ask(c[a],c[b]))
				k[i++] = c[a++];
			else k[i++] = c[b++];
		}
	}
	for(i = l; i <= r; ++i)
		c[i] = k[i];
}

int main()
{
	scanf("%d %d",&N,&Q);
	fflush(stdout);
	for (int i = 0; i < N; ++i)
		c[i] = i;
	sort(0,N-1);
	printf("! ");
	for (int i = 0; i < N; ++i)
		printf("%c", c[i]+'A');
	printf("\n");
	return 0;
}