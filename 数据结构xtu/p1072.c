#include <stdio.h>

int n,m;

struct edge
{
	int a,b,w;
};
struct edge s[3004];
int f[303];

int get_fa(int now)
{
	if (f[now] == now) return now;
	else return f[now] = get_fa(f[now]);
}

int cmp(struct edge a,struct edge b)
{
	return a.w < b.w;
}

void sort(int l,int r)
{
	if (l >= r) return;
	int a = l,b = r;
	struct edge temp = s[(l+r)>>1],t;
	while(a <= b)
	{
		while(cmp(s[a],temp)) ++a;
		while(cmp(temp,s[b])) --b;
		if (a <= b)
		{
			t = s[a]; 
			s[a] = s[b];
			s[b] = t;
			++a;
			--b;
		}
	}
	if(l < b) sort(l,b);
	if(r > a) sort(a,r);
}

int main()
{
	scanf("%d %d", &n,&m);
	int i;
	for (i = 0; i < m; ++i)
		scanf("%d %d %d", &s[i].a,&s[i].b,&s[i].w);
	sort(0,m-1);
	for (i = 1; i <= n; ++i)
		f[i] = i;
	int ans = 0,a,b;
	for (i = 0; i < m; ++i)
	{
		a = get_fa(s[i].a);
		b = get_fa(s[i].b);
		if (a != b)
		{
			f[a] = b;
			ans += s[i].w;
		}
	}
	printf("%d\n", ans);
	return 0;
}
