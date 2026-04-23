#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

constexpr ll INF = 1e18 + 9, MOD = 1e9 + 7, MOD1 = 998244353, MAX = 1e6 + 5;
ll PRIME[MAX+2], SPF[MAX+2]; bool isPRIME[MAX+2];
vector<ll> Divs[MAX+2], prDivs[MAX+2], prDivsall[MAX+2];

bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
void prime(ll n) {
    fill(isPRIME, isPRIME + n + 1, true); isPRIME[0] = isPRIME[1] = false; ll id = 0;
    for(ll i=2; i<=n; i++) { if(isPRIME[i]) { for(ll j=i*i; j<=n; j+=i) { isPRIME[j] = false; } } }
    for(ll i=2; i<=n; i++) { if(id < MAX && isPRIME[i]) { PRIME[id] = i; id++; } }
}
void compDivs(ll n) { for(ll i=1; i<=n; i++) { for(ll j=i; j<=n; j+=i) { Divs[j].push_back(i); } } }
void compPrDivs(ll n, bool unq = true) {
    for(ll i=2; i<=n; i++) if(SPF[i] == 0) {
        for(ll j=i; j<=n; j+=i) { if(SPF[j] == 0) { SPF[j] = i; } prDivs[j].push_back(i); }
    } if(!unq) { for(ll i=2; i<=n; i++) { ll x = i; while(x > 1) { prDivsall[i].push_back(SPF[x]); x /= SPF[x]; } } }
}
vector<ll> getDivs(ll n) {
    vector<ll> divs; for(ll i=1; i*i<=n; i++) if(n % i == 0) { divs.push_back(i); if(i * i != n) { divs.push_back(n/i); } }
    return divs;
}
vector<ll> getPrDivs(ll n, bool unq = true) {
    vector<ll> prdivs;
    for(ll i=2; i*i<=n; i++) if(n % i == 0) {
        if(unq) { prdivs.push_back(i); } while(n % i == 0) { if(!unq) { prdivs.push_back(i); } n /= i; }
    } if(n > 1) { prdivs.push_back(n); } return prdivs;
}

int main() {

    

    return 0;
}