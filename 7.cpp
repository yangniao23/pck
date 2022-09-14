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
    int n, m, h_min = 1E5;
    ll money = 0;
    cin >> n >> m;
    int th[m][2], house[n] = {0};
    rep(i, m) {
        cin >> th[i][0] >> th[i][1];
        th[i][1]--;  // zero-index
        h_min = min(h_min, th[i][1]);
        house[th[i][1]] = th[i][0];
    }

    for (int i = h_min; i < n; ++i) {
        if (house[i] != 0) {
            for (int j = i + 1; j < n; ++j) {
                if (house[j] == 0) {
                    house[j] = house[i];
                    break;
                }
            }
        }
    }

    rep(i, n) money += house[i];

    cout << money << '\n';

    return 0;
}