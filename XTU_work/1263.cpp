#include <cstdio>
using namespace std;
int x1,y1,x2,y2;
int x3,y3,x4,y4;

void swap(int &x1,int &y1,int &x2,int &y2)
{
	int t;
	if (x1 > x2) t = x1, x1 = x2, x2 = t;
	if (y1 > y2) t = y1, y1 = y2, y2 = t;
}

#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	int xb,yb,xe,ye,S,S1;
	while(scanf("%d %d %d %d", &x1,&y1,&x2,&y2) == 4)
	{
		scanf("%d %d %d %d", &x3,&y3,&x4,&y4);
		swap(x1,y1,x2,y2);
		swap(x3,y3,x4,y4);
		xb = Max(x1,x3); yb = Max(y1,y3);
		xe = Min(x2,x4); ye = Min(y2,y4);
		S = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
		if (xb >= xe || yb >= ye) S1 = 0;
		else S1 = (xe - xb) * (ye - yb);
		printf("%d\n",S - S1);
	}
	return 0;
} 
