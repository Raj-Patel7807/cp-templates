#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n-1))); }
inline ll computeXOR(ll n) { if(n%4==0) return n; if(n%4==1) return 1; if(n%4==2) return (n+1); return 0; }
inline ll cntSetBit(ll n) { return (__builtin_popcountll(n)); }
inline ll msbPos(ll n) { if(n == 0) { return -1; } return (63 - (__builtin_clzll(n))); }
inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }
inline ll setBit(ll n, ll pos) { return (n | (1LL << pos)); }
inline ll clearBit(ll n, ll pos) { return (n & (~(1LL << pos))); }
inline ll toggleBit(ll n, ll pos) { return (n ^ (1LL << pos)); }
inline ll updateBit(ll n, ll pos, ll bit) { return (n & (~(1LL << pos)) | (bit << pos)); }

int main() {

    

    return 0;
}