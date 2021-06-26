#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector < string > ans;
int p[10003],num[30];
char s[10003];

#define Max(x,y) ((x)>(y)?(x):(y))

int main()
{
	int l,st;
	while(scanf("%s",s) == 1)
	{
		memset(num, 0, sizeof(num));
		ans.clear();
		l = 0;
		st = 1;
		p[0] = 1;
		num[s[0] - 'a'] = 1;
		for (int i = 1; s[i] != 0; ++i)
		{
			++num[s[i] - 'a'];
			while(num[s[i] - 'a'] > 1) --num[s[l++] - 'a'];
			p[i] = i - l + 1;
			st = Max(p[i],st);
		}
		string temp;
		for (int i = 0; s[i] != 0; ++i)
		{
			if (p[i] == st)
			{
				temp = "";
				for (int j = i - p[i] + 1; j <= i; ++j)
					temp += s[j];
				ans.push_back(temp);
			}
		}
		sort(ans.begin(),ans.end());
		cout << st << endl;
		temp = ans[0];
		cout << temp << endl;
		for (auto i : ans)
		{
			if (i != temp)
			{
				cout << i << endl;
				temp = i;
			}
		}
	}
	return 0;
}