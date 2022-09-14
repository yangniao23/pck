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
    int n, a, s, sht = 1, lng = 1E9, better_min = 1E9, better_max = 1;
    cin >> n;
    rep(i, n) {
        cin >> a >> s;
        if (s == 0) {
            sht = (sht < a) ? a : sht;
        } else if (s == 1) {
            better_min = min(better_min, a);
            better_max = max(better_max, a);
        } else if (s == 2) {
            lng = (lng > a) ? a : lng;
        }
    }

    int m, b;
    cin >> m;
    rep(i, m) {
        cin >> b;
        if (b <= sht)
            cout << 0 << '\n';
        else if (b >= better_min && b <= better_max)
            cout << 1 << '\n';
        else if (b >= lng)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}