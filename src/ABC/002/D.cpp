#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int main() {
    bool relations[12][12];
    memset(relations, false, sizeof(relations));

    int n, m;
    cin >> n >> m;
    rep (i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        relations[x][y] = relations[y][x] = true;
    }

    int ans = 1;
    rep (i, (1 << n)) {
        bool flg = true;

        rep (j, n) rep (k, n) {
            if (j != k && ((i >> j) & 1) && ((i >> k) & 1) && ! relations[j][k]) {
                flg = false;
            }
        }

        if (flg) {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    cout << ans << endl;
}
