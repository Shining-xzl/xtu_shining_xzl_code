#include <cstdio>

using namespace std;

#define Max(x,y) ((x)>(y)?(x):(y))
int s[14];
int p[6];

int main()
{
	int T,ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d", &s[0],&s[1],&s[2],&s[3]);
		scanf("%d %d %d %d", &s[11],&p[1],&p[2],&s[4]);
		scanf("%d %d %d %d", &s[10],&p[4],&p[3],&s[5]);
		scanf("%d %d %d %d", &s[9],&s[8],&s[7],&s[6]);
		ans = p[1] + p[2] + p[3] + p[4];
		for (int i = 0; i < 12; i+=3)
		{
			for (int j = 1; j < 5; ++j)
			{
				ans = Max(ans,s[(i-1+12)%12]+s[i]+s[(i+1)%12]+p[j]);
			}
			ans = Max(ans,p[1]+p[2]+s[(i+1)%12]+s[(i+2)%12]);
			ans = Max(ans,p[3]+p[2]+s[(i+4)%12]+s[(i+5)%12]);
			ans = Max(ans,p[3]+p[4]+s[(i+7)%12]+s[(i+8)%12]);
			ans = Max(ans,p[1]+p[4]+s[(i+10)%12]+s[(i+11)%12]);
		}
		printf("%d\n",ans);
	}
	return 0;
}