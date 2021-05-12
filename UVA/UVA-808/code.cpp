/*
非直角坐标
*/
#include <cstdio>
using namespace std;

struct position
{
	int x,y;
	position () : x(0),y(0) {}
	position (int a,int b) : x(a),y(b) {}
	position operator - (const position &k) const 
	{
		return position(x - k.x, y - k.y);
	}
	position operator + (const position &k) const 
	{
		return position(x + k.x, y + k.y);
	}
};
const int lim = 1e4+3;
position s[lim<<1];
const position f[6] = {{0,-1},{1,-1},{1,0},{0,1},{-1,1},{-1,0}};
void process()
{
	int now = 2,k = 1;
	while(now < lim)
	{
		s[now] = s[now-1] + f[5];
		now++;
		for (int i = 1; i < k; ++i)
		{
			s[now] = s[now-1] + f[0];
			now++;
		}
		for (int i = 1; i < 6; ++i)
			for (int j = 0; j < k; ++j)
			{
				s[now] = s[now-1] + f[i];
				now++;
			}
		k++;
	}
}
#define Abs(x) ((x>0)?(x):(-(x)))
#define Max(x,y) ((x)>(y)?(x):(y))

int main()
{
	process();
	int n,m,res;
	while(scanf("%d %d", &n, &m) == 2)
	{
		if(n == m && n == 0) break;

		position ans = s[n] - s[m];
		if(ans.x * ans.y <= 0)
			res = Max(Abs(ans.x),Abs(ans.y));
		else res = Abs(ans.x + ans.y);
		printf("The distance between cells %d and %d is %d.\n", n,m,res);
	}
	return 0;
} 
