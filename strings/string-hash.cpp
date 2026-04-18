#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct StringHash {
    string s, t;
    ll p1 = 313, m1 = 1e9 + 7; ll p2 = 379, m2 = 1e9 + 9, n;
    vector<ll> p_pow1, p_pow2, inv_pow1, inv_pow2, h1, h2, rh1, rh2;
    ll modPower(ll a, ll b, ll mod) {
        ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans;
    }
    ll modinv(ll a, ll mod) { return modPower(a, mod-2, mod); }
    StringHash(const string& str) : s(str), t(str) {
        n = s.length(); reverse(t.begin(), t.end());
        p_pow1.resize(n+1, 1); p_pow2.resize(n+1, 1); inv_pow1.resize(n+1, 1); inv_pow2.resize(n+1, 1);
        h1.resize(n+1, 0); h2.resize(n+1, 0); rh1.resize(n+1, 0); rh2.resize(n+1, 0);
        ll inv_p1 = modinv(p1, m1); ll inv_p2 = modinv(p2, m2);
        for(ll i = 1; i < n; i++) {
            p_pow1[i] = (p_pow1[i-1] * p1) % m1; p_pow2[i] = (p_pow2[i-1] * p2) % m2;
            inv_pow1[i] = (inv_pow1[i-1] * inv_p1) % m1; inv_pow2[i] = (inv_pow2[i-1] * inv_p2) % m2;
        }
        for(ll i = 0; i < n; i++) {
            h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % m1;
            h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
            rh1[i+1] = (rh1[i] + (t[i] - 'a' + 1) * p_pow1[i]) % m1;
            rh2[i+1] = (rh2[i] + (t[i] - 'a' + 1) * p_pow2[i]) % m2;
        }
    }
    pair<ll, ll> get_hash(ll l, ll r) {
        ll res1 = (((h1[r+1] - h1[l] + m1) % m1) * inv_pow1[l]) % m1;
        ll res2 = (((h2[r+1] - h2[l] + m2) % m2) * inv_pow2[l]) % m2;
        return make_pair(res1, res2);
    }
    pair<ll, ll> get_rev_hash(ll l, ll r) {
        int L = n - 1 - r, R = n - 1 - l;
        ll res1 = (rh1[R + 1] - rh1[L] + m1) % m1 * inv_pow1[L] % m1;
        ll res2 = (rh2[R + 1] - rh2[L] + m2) % m2 * inv_pow2[L] % m2;
        return make_pair(res1, res2);
    }
    pair<ll, ll> concat(pair<ll, ll> left, pair<ll, ll> right, int len_right) {
        ll new1 = (left.first + right.first * p_pow1[len_right]) % m1;
        ll new2 = (left.second + right.second * p_pow2[len_right]) % m2;
        return {new1, new2};
    }
};

int main() {

    string str = "raj_patel_7807";

    StringHash sh(str);

    return 0;
}
