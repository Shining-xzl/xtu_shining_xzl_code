#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
ll x1,x2,y1,y2;

ll pp(ll a,ll p)
{
	ll res = 1ll;
	while(p > 0)
	{
		if (p & 1ll) res = res * a % MOD;
		a = a * a % MOD;
		p >>= 1ll;
	}
	return res;
}

ll askll(ll l,ll r,ll x) // 求SUM{[x/i]}
{
	ll res = 0ll,len,p,i,temp;
	r = min(r,x);
	while(l <= r)
	{
		i = l;
		p = min(r,x/(x/i));
		len = p - i + 1;
		temp = x/i;
		res += temp * len % MOD;
		res %= MOD;
		l = p+1;
	}
	return res;
}

ll ask(ll l,ll r,ll x) //求SUM{[x/i]^2}
{
	ll res = 0ll,len,p,i,temp;
	r = min(r,x);
	while(l <= r)
	{
		i = l;
		p = min(r,x/(x/i));
		len = p - i + 1;
		temp = x/i;
		res += temp*temp % MOD * len % MOD;
		res %= MOD;
		l = p+1;
	}
	return res;
}

ll askj(ll l,ll r,ll x) // 求SUM{[i/x]}
{
	ll res = 0;
	ll b = r/x;
	res = (b) * (b-1) / 2;
	res = res * x % MOD;
	res = (res + ((r%x)+1) * b) % MOD;
	return res;
}


ll askx(ll l,ll r,ll x1,ll x2) // 求SUM{[i/x]*[x/i]}
{
	ll res = 0ll,p,i,temp;
	ll sum;
	r = min(r,x2);
	while(l <= r)
	{
		i = l;
		p = min(r,x2/(x2/i));
		temp = x2/i;
		sum = 0;
		sum = askj(0,p,x1) - askj(0,i-1,x1) + MOD;
		sum %= MOD;	
		res += sum * temp % MOD;
		res %= MOD;
		l = p+1;
	}
	return res;
}

int main(){
	int T;
	ll f6 = pp(6,MOD-2);
	cin>>T;
	ll ans;
	ll temp,a,b,lenx,leny;
	while(T--){
		cin >> x1 >> x2 >> y1 >> y2;
		lenx = x2 - x1 + 1;
		leny = y2 - y1 + 1;
		ans = ask(x1,x2,x2) * leny % MOD + ask(y1,y2,y2) * lenx % MOD;
		ans %= MOD;
		b = x2/x1;
		temp = b * (b - 1) % MOD * (b * 2 - 1) % MOD * f6 % MOD;
		temp = temp * x1 % MOD;
		a = x2 % x1 + 1;
		temp = temp + b * b % MOD * a % MOD;
		temp = (temp * leny) % MOD;		
		ans = (ans + temp) % MOD;		
		b = y2/y1;
		temp = b * (b - 1) % MOD * (b * 2 - 1) % MOD * f6 % MOD;
		temp = temp * y1 % MOD;
		a = y2 % y1 + 1;
		temp = temp + b * b % MOD * a % MOD;
		temp = (temp * lenx) % MOD;		
		ans = (ans + temp) % MOD;
		ans = (ans + 2 * askx(x1,x2,x1,x2) % MOD * leny % MOD) %MOD;
		ans = (ans + 2 * askx(y1,y2,y1,y2) % MOD * lenx % MOD) %MOD;
		temp = askll(x1,x2,x2) * askj(y1,y2,y1) % MOD * 2;
		ans = (ans + temp) % MOD;
		temp = askll(y1,y2,y2) * askj(x1,x2,x1) % MOD * 2;
		ans = (ans + temp) % MOD;
		temp = askll(x1,x2,x2) * askll(y1,y2,y2) % MOD * 2;
		ans = (ans + temp) % MOD;
		temp = askj(x1,x2,x1) * askj(y1,y2,y1) % MOD * 2;
		ans = (ans + temp) % MOD;
		cout << ans << endl;
	}
	return 0;
}