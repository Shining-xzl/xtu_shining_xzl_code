#include <cstdio>

using namespace std;

const int lim = 1e5+3;

double l[lim],r[lim];
int n;
double m;

bool check(double stand)
{
	double num = 0;
	for (int i = 0; i < n; ++i)
	{
		if(stand >= r[i]) num += 1;
		else if(stand > l[i]) num += (stand - l[i]) / (r[i] - l[i]);
		else continue;
	}
	return num >= m;
}

int main()
{
	scanf("%d %lf", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%lf %lf", &l[i],&r[i]);
	double L = 0,R = 1e9,mid;
	while(R - L > 1e-5)
	{
		mid = (R + L) / 2;
		if(check(mid)) R = mid;
		else L = mid;
	}
	printf("%f\n",R);
	return 0;
}