
// We claim the answer is NO if and only if the elements are pairwise distinct.
// If any element has two occurrences, we can trivially select them as the two subarrays. 
// Otherwise, since all elements are distinct, choosing a subarray is the same as choosing
//  the set bits of a 1e9 digit long binary number. Since every number has a unique binary
//   representation, no two subarrays can have the same sum.

#include <cstdio>
#include <set>
using namespace std;

bool check()
{
	int n,x;
	set<int> s;
	bool flag=1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(flag)
		{
			if(s.count(x)) flag=0;
			else s.insert(x);
		}
	}
	if(flag) return false;
	else return true;
}

int main()
{
	// freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
		if(check())
			printf("YES\n");
		else printf("NO\n");
	return 0;
}