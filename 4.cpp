#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define ll long long
const ll mod = 1000000007;
inline int roundup(int a, int b) { return (((a + (b - 1)) / b)); }
inline ll powmod(ll x, ll y) {
    ll res = 1;
    for (ll i = 0; i < y; i++) {
        res = res * x % mod;
    }
    return res;
}
using namespace std;

signed main(void) {
    int n, gr = 0;
    cin >> n;
    gr = n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) gr--;
    }

    if (gr == 0) gr = 1;
    cout << gr << '\n';
    return 0;
}