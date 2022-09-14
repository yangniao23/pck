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
    int x[3], y[3], win = 0, lose = 0;
    rep(i, 3) {
        cin >> x[i] >> y[i];
        int tmp = x[i] - y[i];
        if (tmp == -1 || tmp == 2)
            win++;
        else if (tmp == -2 || tmp == 1)
            lose++;
    }
    if (win < lose)
        cout << 1;
    else if (win == lose)
        cout << -1;
    else
        cout << 0;
    cout << '\n';
    return 0;
}