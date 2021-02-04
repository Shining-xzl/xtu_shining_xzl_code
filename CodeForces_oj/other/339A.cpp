#include <cstdio>
#include <cstring>
using namespace std;
char s[103];
short a[60],num;

void sort(short l,short r)
{
	if(l==r) return;
	int i=l,j=r,mid=a[(l+r)>>1],temp;
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(i<r) sort(i,r);
	if(l<j) sort(l,j);
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%s",&s);
	short len=strlen(s);
	for(short i=0;i<len;i+=2)
		a[++num]=s[i]-48;
	sort(1,num);
	for(short i=1;i<num;i++)
		printf("%d+",a[i]);
	printf("%d\n",a[num]);
	return 0;
}
