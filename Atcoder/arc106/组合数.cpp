#include <bits/stdc++.h>
using namespace std;

namespace Combinatorial_Number // ×éºÏÊý 
{
	typedef long long ll;
	
  	const int N = 1e5 + 10, mod = 1e9 + 7;
	ll jc[N], jc_inv[N];

  	inline ll C (int x, int y) { 
  		// C(n, m) = C(n, n - m) = C(n - 1,m - 1) + C(n - 1, m)
  		// C(n, 0)=1 C(n, n)=1 C(0, 0)=1
    	if (x < 0 || y < 0 || y > x) return 0;
    	if (y == 0 || y == x) return 1;
    	return jc[x] * jc_inv[y] % mod * jc_inv[x - y] % mod;
  	}

	inline ll qpow (ll a, ll b, ll mod) {
    	ll res = 1;
    	while (b)
    	{
      		if (b & 1) res = res * a % mod;
      		a = a * a % mod;
      		b >>= 1;
    	}
    	return res % mod;
  	}

  	inline void init () {
    	jc[1] = 1;
    	for (int i=2; i<N; i++)
      		jc[i] = jc[i - 1] * i % mod;
      		
    	jc_inv[N - 1] = qpow(jc[N - 1], mod - 2, mod);
    	
    	for (int i = N-2; i>=1; i--)
      		jc_inv[i] = (jc_inv[i + 1] * (i + 1)) % mod;
  	}
} using Combinatorial_Number::C;

int main()
{
	Combinatorial_Number::init();
	cout << C(55, 49) << endl;
} 
