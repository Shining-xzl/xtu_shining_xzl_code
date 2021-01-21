#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int n;
string s[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int a[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};

int main()
{
	int i,j,k;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<13;i++)
		{
			k=n/a[i];
			n%=a[i];
			for(j=1;j<=k;j++)
				cout<<s[i];
		}
		printf("\n");
	}
	return 0;
}
