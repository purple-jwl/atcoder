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

const int INF = 1 << 29;
const ll MOD = 1e+9 + 7;

ll nCr[905][905];

int main() {
    nCr[0][0] = 1;
    rep (i, 901) rep (j, 901) {
        if (i) nCr[i][j] += nCr[i - 1][j];
        if (i && j) nCr[i][j] += nCr[i - 1][j - 1];
        nCr[i][j] %= MOD;
    }

    int R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;

    ll ans = 0;
    rep (i, (1 << 4)) {
        int x = 0;
        int y = 0;
        if ((i >> 0) & 1) x++;
        if ((i >> 1) & 1) x++;
        if ((i >> 2) & 1) y++;
        if ((i >> 3) & 1) y++;
        if (X - x < 0 || Y - y < 0) continue;
        int s = (X - x) * (Y - y);
        if (s < D + L) continue;
        int sign = (popcount(i) % 2) ? -1 : 1;
        ans += nCr[s][D] * nCr[s - D][L] * sign;
        ans %= MOD;
    }

    while (ans < 0) ans += MOD;
    ans = ans * (R - X + 1) * (C - Y + 1) % MOD;
    cout << ans << endl;
}
