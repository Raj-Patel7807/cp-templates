#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct HLD {
    int n, cur;
    std::vector<int> siz, top, dep, par, in, out, ord;
    std::vector<std::vector<int>> adj;
    HLD() {}
    HLD(int n) { init(n); }

    // Initialize the tree structures : O(n)
    void init(int n) {
        this->n = n;
        siz.resize(n); top.resize(n); dep.resize(n); par.resize(n);
        in.resize(n); out.resize(n); ord.resize(n);
        cur = 0; adj.assign(n, {});
    }

    // Add an undirected edge : O(1)
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

    // Prepares the tree for queries : O(n)
    void work(int root = 0) {
        top[root] = root; dep[root] = 0; par[root] = -1;
        dfs1(root); dfs2(root);
    }

    // First DFS to compute subtree sizes and reorder adjacency list : O(n)
    void dfs1(int u) {
        if (par[u] != -1) { adj[u].erase(std::find(adj[u].begin(), adj[u].end(), par[u])); }
        siz[u] = 1;
        for (auto &v : adj[u]) {
            par[v] = u; dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) { std::swap(v, adj[u][0]); }
        }
    }
    
    // Second DFS to compute in/out times and top chains : O(n)
    void dfs2(int u) {
        in[u] = cur++; ord[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    
    // Finds the lowest common ancestor (LCA) of u and v : O(log n)
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) { u = par[top[u]]; }
            else { v = par[top[v]]; }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    // Computes the distance between u and v : O(log n)
    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    
    // Finds the k-th ancestor of node u : O(log n)
    int jump(int u, int k) {
        if (dep[u] < k) { return -1; }
        int d = dep[u] - k;
        while (dep[top[u]] > d) { u = par[top[u]]; }
        return ord[in[u] - dep[u] + d];
    }
    
    // Checks if u is an ancestor of v : O(1)
    bool isAncester(int u, int v) { return in[u] <= in[v] && in[v] < out[u]; }
    
    // Returns the depth of a node : O(1)
    int getDepth(int u) { return dep[u]; }
    
    // Returns the par of a node : O(1)
    int getpar(int u) { return par[u]; }
    
    // Returns the size of the subtree rooted at node u : O(1)
    int getSubtreeSize(int u) { return siz[u]; }
 
    // Finds the par of u when tree is rooted at v : O(log n)
    int rootedpar(int u, int v) {
        std::swap(u, v);
        if (u == v) { return u; }
        if (!isAncester(u, v)) { return par[u]; }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    // Computes the size of the subtree of v when rooted at u : O(log n)
    int rootedSize(int u, int v) {
        if (u == v) return n;
        if (!isAncester(v, u)) return siz[v];
        return n - siz[rootedpar(u, v)];
    }
    
    // Computes LCA of three nodes a, b, and c : O(log n)
    int rootedLca(int a, int b, int c) { return lca(a, b) ^ lca(b, c) ^ lca(c, a); }
};

int main() {

    

    return 0;
}