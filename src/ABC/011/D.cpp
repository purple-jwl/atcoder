#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int main() {
    double prob[1001][1001] = {0.0};
    prob[0][0] = 1.0;

    rep (i, 1001) rep (j, 1001) {
        if (i) {
            prob[i][j] += prob[i - 1][j] / 2;
        }
        if (i && j) {
            prob[i][j] += prob[i - 1][j - 1] / 2;
        }
    }

    int n, d, x, y;
    cin >> n >> d >> x >> y;

    x = abs(x);
    y = abs(y);

    double ans = 0.0;

    if (x % d == 0 && y % d == 0) {
        x /= d;
        y /= d;
        rep (ud, n + 1) { // up and down
            int lr = n - ud; // left and right
            if (ud < y || (ud - y) % 2) continue;
            if (lr < x || (lr - x) % 2) continue;
            ans += prob[n][ud] * prob[ud][(ud - y) / 2] * prob[lr][(lr - x) / 2];
        }
    }

    printf("%.15f\n", ans);
 }
