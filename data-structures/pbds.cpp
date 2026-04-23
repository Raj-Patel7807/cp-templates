#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class key, class value, class cmp = std::less<key>>
using idmap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> using idset = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// For `idset`:
//     find_by_order(k) - O(log n) - Find the k-th smallest element (0-based index);
//     order_of(value) - O(log n) - Find the index of a value in the sorted set;
//     Can find the k-th smallest element, or get the position of a value in sorted order;

int main() {

    idset<int> st;

    idmap<int, int> mp;

    return 0;
}