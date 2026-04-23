#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

constexpr ll INF = 1e18 + 9, MOD = 1e9 + 7, MOD1 = 998244353, MAX = 1e6 + 5;
ll FACT[MAX+2], invFACT[MAX+2];

inline ll power(ll a, ll b, ll mod = MOD) {
    ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans;
}

inline ll modMult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modInv(ll a, ll mod = MOD) { return power(a, mod-2, mod); }
inline ll modDiv(ll a, ll b, ll mod = MOD) { return modMult(a, modInv(b, mod), mod); }
inline void factorial(ll n, ll mod = MOD) {
    FACT[0] = invFACT[0] = 1; for(ll i=1; i<=n; i++) { FACT[i] = (FACT[i-1] * i) % mod; }
    invFACT[n] = modInv(FACT[n], mod); for(ll i=n-1; i>0; i--) { invFACT[i] = (invFACT[i+1] * (i+1)) % mod; }
}
inline ll nCr(ll n, ll r, ll mod = MOD) { if(r > n) return 0; return ((FACT[n] * ((invFACT[r] * invFACT[n-r]) % mod)) % mod); }
inline ll nCrLucas(ll n, ll r, ll mod = MOD) {
    if(r > n) return 0; if(r == 0) return 1; return ((nCrLucas(n/mod, r/mod, mod) * nCr(n % mod, r % mod, mod)) % mod);
}

int main() {

    

    return 0;
}