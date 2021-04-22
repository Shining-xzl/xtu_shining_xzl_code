/*

位运算恒等式：
	a + b = 2 * (a & b) + (a ^ b)

在本问题中，求解（x,y,z）
	存在方程组：
	x ^ y = a1; x & y = b1;
	x ^ z = a2; x & y = b2;
	y ^ z = a3; y & z = b3;

利用恒等式转换：
	x + y = a1 + 2 * b1;
	x + z = a2 + 2 * b2;
	z + y = a3 + 2 * b3;

*/

#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int a1,a2,a3;
	int b1,b2,b3;
	int x,y,z;
	while(T--)
	{
		scanf("%d %d %d", &a1,&a2,&a3);
		scanf("%d %d %d", &b1,&b2,&b3);
		a1 = a1 + 2 * b1;
		a2 = a2 + 2 * b2;
		a3 = a3 + 2 * b3;
		x = a1 + a2 - a3 >> 1;
		y = a1 - x;
		z = a3 - y;
		printf("%d %d %d\n",x,y,z ); 
	}
}