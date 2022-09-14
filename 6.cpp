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
    int n, t, current_time = 0, cnt = 0, is_delay = 0;
    cin >> n >> t;
    int a[n];
    rep(i, n) {
        cin >> a[i];

        current_time += t;
        if (current_time > a[i]) {
            if (is_delay) break;
            is_delay = 1;
        }
        if (current_time <= a[i]) {
            is_delay = 0;
            current_time = a[i];
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}