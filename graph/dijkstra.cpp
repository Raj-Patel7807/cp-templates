#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

constexpr ll INF = 1e18 + 9;

vector<ll> dijkstra(ll root, vector<vector<pair<ll, ll>>>& adj) {
    ll n = adj.size();
    vector<ll> dp(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, root});
    dp[root] = 0;

    while(!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if(d > dp[u]) continue;

        for(auto &[v, w] : adj[u]) {
            if(dp[u] + w < dp[v]) {
                dp[v] = dp[u] + w;
                pq.push({dp[v], v});
            }
        }
    }

    return dp;
}

int main() {

    

    return 0;
}