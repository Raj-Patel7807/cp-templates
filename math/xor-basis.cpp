#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }

int main() {

    ll bit = 32, sz = 0;
    vector<ll> basis(bit+1), basis1; // basis for max, min xor AND basis1 for all uniqe xor..
    
    auto insertVec = [&](ll msk) {
        ll mask = msk;
        for(auto i : basis1) mask = min(mask, mask ^ i);
        if(mask) basis1.push_back(mask);
        for(ll i=bit; i>=0; i--) if(getBit(msk, i)) {
            if(!basis[i]) {
                sz++; basis[i] = msk; return;
            } msk ^= basis[i];
        }
    };
    
    

    return 0;
}