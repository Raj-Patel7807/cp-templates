#include <bits/stdc++.h>
using namespace std;

class DSU {
private :
    #define ll long long int

    vector<ll> parent, size, edge, rank, dist;
public :
    DSU(ll n) {
        parent.resize(n + 1); size.assign(n + 1, 1);
        rank.assign(n + 1, 0); edge.assign(n + 1, 0);
        dist.assign(n + 1, 0); iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x) {
        if(x != parent[x]) {
            ll root = find(parent[x]);
            dist[x] += dist[parent[x]]; parent[x] = root;
        } return parent[x];
    }
    void unitebysize(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            parent[y] = x; size[x] += size[y];
            edge[x] += edge[y] + 1; dist[y] = 1;
        } else { edge[x]++; }
    }
    void unitebyrank(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            parent[y] = x; dist[y] = 1;
            if(rank[x] == rank[y]) rank[x]++;
            edge[x] += edge[y] + 1;
        } else { edge[x]++; }
    }
    ll componentCount(ll n) {
        ll count = 0;
        for(ll i=1; i<=n; ++i) { if(find(i) == i) ++count; } return count;
    }
    bool isSame(ll x, ll y) { return find(x) == find(y); }
    ll getSize(ll x) { return size[find(x)]; }
    ll getEdgeCount(ll x) { return edge[find(x)]; }
};

int main() {

    long long int n;
    cin >> n;

    DSU ds(n);

    return 0;
}