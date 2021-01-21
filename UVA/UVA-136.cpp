#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <set>
using namespace std;
typedef long long LL;

int main()
{
	priority_queue<LL,vector<LL>,greater<LL> > q;
	set<LL> ss;
	int con=1;
	LL temp,k;
	q.push(1);
	while(!q.empty())
	{
		temp=q.top();
		q.pop();
		if(con==1500) break;
		con++;
		k=temp<<1;
		if(!ss.count(k))
		{
			q.push(k);
			ss.insert(k);
		}	
		k=(temp<<1)+temp;
		if(!ss.count(k))
		{
			q.push(k);
			ss.insert(k);
		}
		k=(temp<<2)+temp;
		if(!ss.count(k))
		{
			q.push(k);
			ss.insert(k);
		}
	}
	printf("The 1500'th ugly number is %lld\n",temp);
	return 0;
}
