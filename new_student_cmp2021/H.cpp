/*

思维概率题

将n-1条边看作为n-1个球，
左边a个红球，中间b个黑球（终止边），右面c个蓝球
每轮游戏只能从外向内选（因为有丢弃规则）

考虑对于第x个球，它被选择的概率实际上只与(他到最远黑球的距离)有关
举个例子：
	考虑1，2，3，4，5，6，7，8号球，终止球为3，4号球
	对于7号球，他被选择的概率等价于 在3，4，5，6，7号球的状态下，选择7号球的概率。
		证明等价关系：
			将一轮完整的选择看成数字的一个排列，
			则1 2 8的排列为（3，4，5，6，7）的公共前缀，证明完毕
	1，2，8号球的选择于7号球无关，在3，4，5，6，7的状态下，选择一次，7号球必然被剔除，
	所以（3，4，5，6，7）为等概率体，选到7的概率为1/5。

*/

#include <cstdio>

using namespace std;
int n,b1,b2;

int main()
{
	while(scanf("%d %d %d", &n,&b1,&b2) == 3)
	{
		for (int i = 1; i < b1; ++i)
			printf("1/%d\n", b2-i);
		for (int i = b1; i < b2; ++i)
			printf("1/%d\n", b2-b1);
		for (int i = b2; i < n; ++i)
			printf("1/%d\n", i-b1+1);
		printf("\n");
	}	
	return 0;
}