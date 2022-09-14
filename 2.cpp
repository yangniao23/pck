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
    int low = 0, high = 0, d[2], m[2], dm[2];
    cin >> d[0] >> m[0];
    dm[0] = d[0] * 10 + m[0];
    if (dm[0] >= 375) high = 1;

    cin >> d[1] >> m[1];
    dm[1] = d[1] * 10 + m[1];
    if (dm[0] < dm[1]) low = 1;

    if (low)
        cout << 0 << '\n';
    else if (high)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
    return 0;
}