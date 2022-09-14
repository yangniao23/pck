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

struct Corr {
    int y;
    int x;
    int depth;
    bool edit;
};
int h, w, sh, sw, gh, gw, y, x, depth;
bool edit;
vector<string> vec;
vector<int> y_vec = {0, 0, -1, +1};
vector<int> x_vec = {-1, +1, 0, 0};

int bfs() {
    queue<Corr> q;
    Corr start = {sh, sw, 0, false};
    q.emplace(start);

    while (!q.empty()) {
        Corr now = q.front();
        q.pop();
        y = now.y, x = now.x, depth = now.depth, edit = now.edit;
        char state = vec[y][x];

        if (y == gh && x == gw) return depth;

        rep(i, 4) {
            Corr next = {y + y_vec[i], x + x_vec[i], depth + 1, edit};
            if (0 <= next.y && next.y <= h - 1 && 0 <= next.x &&
                next.x <= w - 1 && vec[next.y][next.x] != '#') {
                if (state == 'S' || state == '.') {
                    q.push(next);
                } else {
                    if (state == 'U') {
                        if (i != 0 && next.edit == false) {
                            next.edit = true;
                            // vec[next.y][next.x] = '#';
                            q.push(next);
                        } else if (i == 0)

                            q.push(next);
                    }
                    if (state == 'D') {
                        if (i != 1 && next.edit == false) {
                            next.edit = true;
                            q.push(next);
                        } else if (i == 1)
                            q.push(next);
                    }
                    if (state == 'L') {
                        if (i != 2 && next.edit == false) {
                            next.edit = true;
                            q.push(next);
                        } else if (i == 2)
                            q.push(next);
                    }
                    if (state == 'R') {
                        if (i != 3 && next.edit == false) {
                            next.edit = true;
                            q.push(next);
                        } else if (i == 3)
                            q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

signed main(void) {
    cin >> h >> w;
    vec.resize(h);
    rep(i, h) {
        cin >> vec[i];
        rep(j, (int)vec[i].size()) {
            if (vec[i][j] == 'S') {
                sh = i;
                sw = j;
            }
            if (vec[i][j] == 'G') {
                gh = i;
                gw = j;
            }
        }
    }

    cout << bfs() << '\n';

    return 0;
}