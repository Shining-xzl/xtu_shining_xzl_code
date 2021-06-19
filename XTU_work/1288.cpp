#include <cstdio>
#include <cstring>
using namespace std;

int read()
{
	char c = getchar();
	int res = 0;
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

int R[103],L[103],val[103],op;
int Rx[103],Lx[103],valx[103],opx;

void build(int id,int x,int *L,int *R,int *val,int &op)
{
	if (x < val[id])
	{
		if (L[id] == -1)
		{
			L[id] = ++op;
			val[op] = x;
		}
		else build(L[id],x,L,R,val,op);
	}
	else
	{
		if (R[id] == -1)
		{
			R[id] = ++op;
			val[op] = x;
		}
		else build(R[id],x,L,R,val,op);
	}
}

bool check(int ida,int idb)
{
	if (ida == -1 && idb != -1) return 0;
	if (idb == -1 && ida != -1) return 0;
	if (ida == -1 && idb == -1) return 1;
	if(val[ida] != valx[idb]) return 0;
	if (!check(R[ida],Rx[idb])) return 0;
	if (!check(L[ida],Lx[idb])) return 0;
	return 1;
}

int main()
{
	int T,n,m,x;
	T = read();
	while(T--)
	{
		memset(R, -1, sizeof(R));
		memset(L, -1, sizeof(L));
		n = read(); m = read();
		x = read();
		val[1] = x;
		op = 1;
		for (int i = 1; i < n; ++i)
		{
			x = read();
			build(1,x,L,R,val,op);
		}
		for (int i = 0; i < m; ++i)
		{
			memset(Rx, -1, sizeof(Rx));
			memset(Lx, -1, sizeof(Lx));
			printf("%d: ",i+1);
			x = read();
			valx[1] = x;
			opx = 1;
			for (int j = 1; j < n; ++j)
			{
				x = read();
				build(1,x,Lx,Rx,valx,opx);
			}
			if (check(1,1)) puts("Yes");
			else puts("No");
		}
		putchar('\n');
	}
	return 0;
}