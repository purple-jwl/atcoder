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

int main() {
    int dp[300][300];

    int n, m;
    cin >> n >> m;

    rep (i, n) rep (j, n) {
        dp[i][j] = (i == j) ? 0 : INF;
    }

    rep (i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        dp[a][b] = dp[b][a] = t;
    }

    rep (k, n) rep (i, n) rep (j, n) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    int ans = INF;
    rep (i, n) {
        int maxd = 0;
        rep (j, n) {
            maxd = max(maxd, dp[i][j]);
        }
        ans = min(ans, maxd);
    }

    cout << ans << endl;
}
