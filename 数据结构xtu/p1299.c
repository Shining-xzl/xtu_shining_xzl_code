#include <stdio.h>
#include <string.h>
char a[1003],b[1003];

int cmp()
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int i,len;
	char p,q;
	if(lena < lenb) len = lena;
	else len = lenb;
	for (i = 0; i < len; ++i)
	{	
		p = a[i];
		q = b[i];
		if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
		if(b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;
		if(a[i] < b[i]) return -1;
		else if(a[i] > b[i]) return 1;
		if(p != q)
			return p < q ? -1 : 1;
	}
	if(lena == lenb) return 0;
	if(lena > lenb) return 1;
	else return -1;
}

int main()
{
	gets(a);
	gets(b);
	printf("%d\n",cmp());
	return 0;
}