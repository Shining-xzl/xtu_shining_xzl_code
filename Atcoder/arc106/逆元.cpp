#include <bits/stdc++.h>
using namespace std;

namespace inverse_element // ÄæÔª 
{
	typedef long long ll;
	
	const int N = 1e5 + 5, mod = 1e9 + 7;
	ll inv[N];
	 
	void inverse (ll n, ll p) {
    	inv[1] = 1;
    	for (int i=2; i<=n; ++i)
			inv[i] = (p - p / i) * inv[p % i] % p;
	}
	
	
	void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
    	if (!b) {
			d = a;
			x = 1;
			y = 0;
		} else {
			exgcd(b, a % b, d, y, x);
			y -= x * (a / b); 
		}
	}

	ll inverse_ex (ll a, ll n) {
    	ll d, x, y;
    	exgcd (a, n, d, x, y);
    	return d == 1? (x + n) % n: -1;
	}


	inline ll qpow(ll a, ll b, ll mod) {
    	ll res = 1;
    	while (b)
    	{
      		if (b & 1) res = res * a % mod;
      		a = a * a % mod;
      		b >>= 1;
    	}
    	return res % mod;
  	}
	
	inline ll inverse_qp(ll a) {
    	return qpow(a, mod - 2, mod);
  	}
} 

int main () {
	
} 
