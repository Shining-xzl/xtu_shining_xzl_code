#include <cstdio>
using namespace std;
char s[3000];

int main()
{
	bool flag = 0;
	int pos = -1;
	scanf("%s",s);
	for (int i = 0; s[i] != 0; ++i)
	{
		if(s[i] == '.')
		{
			if(s[i+1] - '0' > 4)
			s[i-1] += 1;
			s[i] = 0;
			pos = i-1;
			break;
		}
	}	
	if(pos == -1) printf("%s\n",s);
	else 
	{
		while(pos >=0 && s[pos] - '0' > 9)
		{
			s[pos] -= 10;
			if(pos == 0) flag = 1;
			else s[pos-1] += 1;
			pos--;
		}
		if(flag) printf("1");
		printf("%s\n",s);
	}
	return 0;
}
