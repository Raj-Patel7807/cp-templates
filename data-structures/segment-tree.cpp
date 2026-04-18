#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class segTree {
private:
    struct Node {
        ll sum, lazyAdd, lazySet;
        Node() : sum(0), lazyAdd(0), lazySet(LLONG_MIN) {}
    };
    ll n; vector<Node> seg;
public:
    segTree(ll n) : n(n) { seg.resize(4 * n + 5); }
    Node merge(const Node& L, const Node& R) {
        Node P;
        P.sum = L.sum + R.sum;
        return P;
    }
    void push(ll idx, ll low, ll high) {
        Node& node = seg[idx];
        if(node.lazySet != LLONG_MIN) {
            node.sum = (high - low + 1) * node.lazySet;
            if(low != high) {
                seg[2*idx + 1].lazySet = node.lazySet;
                seg[2*idx + 1].lazyAdd = 0;
                seg[2*idx + 2].lazySet = node.lazySet;
                seg[2*idx + 2].lazyAdd = 0;
            }
            node.lazySet = LLONG_MIN;
        }
        if(node.lazyAdd != 0) {
            node.sum += (high - low + 1) * node.lazyAdd;
            if(low != high) {
                if(seg[2*idx + 1].lazySet != LLONG_MIN) {
                    seg[2*idx + 1].lazySet += node.lazyAdd;
                } else {
                    seg[2*idx + 1].lazyAdd += node.lazyAdd;
                }
                if(seg[2*idx + 2].lazySet != LLONG_MIN) {
                    seg[2*idx + 2].lazySet += node.lazyAdd;
                } else {
                    seg[2*idx + 2].lazyAdd += node.lazyAdd;
                }
            }
            node.lazyAdd = 0;
        }
    }
    void build(ll idx, ll low, ll high, const vector<ll>& arr) {
        if(low == high) { seg[idx].sum = arr[low]; return; }
        ll mid = (low + high)/2;
        build(2*idx + 1, low, mid, arr);
        build(2*idx + 2, mid+1, high, arr);
        seg[idx] = merge(seg[2*idx + 1], seg[2*idx + 2]);
    }
    void updateAdd(ll idx, ll low, ll high, ll ql, ll qr, ll val) {
        push(idx, low, high);
        if(qr < low || ql > high) { return; }
        if(ql <= low && qr >= high) {
            seg[idx].lazyAdd += val;
            push(idx, low, high); return;
        }
        ll mid = (low + high)/2;
        updateAdd(2*idx + 1, low, mid, ql, qr, val);
        updateAdd(2*idx + 2, mid+1, high, ql, qr, val);
        seg[idx] = merge(seg[2*idx + 1], seg[2*idx + 2]);
    }
    void updateSet(ll idx, ll low, ll high, ll ql, ll qr, ll val) {
        push(idx, low, high);
        if(qr < low || ql > high) { return; }
        if(ql <= low && qr >= high) {
            seg[idx].lazySet = val;
            seg[idx].lazyAdd = 0;
            push(idx, low, high); return;
        }
        ll mid = (low + high)/2;
        updateSet(2*idx + 1, low, mid, ql, qr, val);
        updateSet(2*idx + 2, mid+1, high, ql, qr, val);
        seg[idx] = merge(seg[2*idx + 1], seg[2*idx + 2]);
    }
    Node query(ll idx, ll low, ll high, ll ql ,ll qr) {
        Node P;
        push(idx, low, high);
        if(qr < low || ql > high) { return P; }
        if(ql <= low && qr >= high) { return seg[idx]; }
        ll mid = (low + high)/2;
        P = merge(query(2*idx + 1, low, mid, ql, qr), query(2*idx + 2, mid+1, high, ql, qr));
        return P;
    }
};

int main() {

    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for(auto &i : arr) cin >> i;

    segTree st(n);
    st.build(0, 0, n-1, arr);

    return 0;
}