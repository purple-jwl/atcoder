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
    int w, n, k;
    int a[50], b[50];
    cin >> w >> n >> k;
    rep (i, n) cin >> a[i] >> b[i];

    int dp[10001][51];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int ans = 0;
    rep (i, n) for (int j = w; j >= 0; j--) rep (l, k) {
        if (dp[j][l] == -1 || a[i] + j > w) continue;
        dp[a[i] + j][l + 1] = max(dp[a[i] + j][l + 1], dp[j][l] + b[i]);
        ans = max(ans, dp[a[i] + j][l + 1]);
    }

    cout << ans << endl;
}
