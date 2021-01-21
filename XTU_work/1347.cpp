#include <cstdio>
#include <vector>
using namespace std;

char s[34];
vector<char> ans;
int len;
vector<char>::iterator it;

void work(int x)
{
	int a=x,b=x+1,temp,l;
	char k;
	if(ans[a]==ans[b])
	{
		temp=2;
		while(a>0&&ans[a]==ans[a-1])
		{
			temp++;
			a--;
		}
		while(b<len-1&&ans[b]==ans[b+1])
		{
			temp++;
			b++;
		}
		if(temp>2)
		{
			ans.erase(ans.begin()+a,ans.begin()+b+1);
			len-=temp;
		}
	}
	else
	{
		l=a;
		k=ans[a];
		ans[a]=ans[b];
		ans[b]=k;
		temp=1;
		while(a>0&&ans[a]==ans[a-1])
		{
			temp++;
			a--;
		}
		if(temp>2)
		{
			ans.erase(ans.begin()+a,ans.begin()+l+1);
			len-=temp;
			b-=temp;
		}
		l=b;
		temp=1;
		while(b<len-1&&ans[b]==ans[b+1])
		{
			temp++;
			b++;
		}
		if(temp>2)
		{
			ans.erase(ans.begin()+l,ans.begin()+b+1);
			len-=temp;
		}
	}
}

int main()
{
	int time,i,m,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		ans.clear();
		for(i=0;s[i]!='\0';i++)
			ans.push_back(s[i]);
		len=i;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			work(x-1);
			if(ans.empty()) 
				printf("Over");
			else 
			{
				for(it=ans.begin();it!=ans.end();it++)
				printf("%c",*it);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
} 
