#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int direction[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
int Start,End;
int dis[100];

struct node
{
	int now,len;
	node(int a,int b) : now(a),len(b) {}
	bool operator < (const node &x) const
	{
		return len > x.len;
	}
};

int spfa()
{
	priority_queue< node > q;
	dis[Start] = 0;
	q.push( node(Start,0) );
	int x,y,len,xx,yy,temp;
	while(!q.empty())
	{
		temp = q.top().now;
		if(temp == End) break;
		x = temp / 8;
		y = temp % 8;
		len = q.top().len;
		q.pop();
		if(dis[temp] < len) continue;
		for(int i = 0; i < 8; ++i)
		{
			xx = x + direction[i][0];
			yy = y + direction[i][1];
			if(xx < 0 || xx > 7 || yy < 0 || yy > 7)
				continue;
			temp = xx*8 + yy;
			if(dis[temp] > len+1)
			{
				dis[temp] = len + 1;
				q.push( node(temp,len+1) );
			}
		}
	}
	return dis[End];
}

int main()
{
	char s[3],e[3];
	while(scanf("%s %s",s,e) == 2)
	{
		Start = (s[0] - 'a')*8 + '8' - s[1]; 
		End = (e[0] - 'a')*8 + '8' - e[1];
		memset(dis, INF, sizeof(dis));
		printf("To get from %s to %s takes %d knight moves.\n", s,e,spfa());
	}
	return 0;
} 
