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
};
const int lim = 1e4+3;
position s[lim];
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	return 0;
} 
