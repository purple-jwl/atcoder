#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
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
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef long long ll;

/* --- INFやMODの値が適切か確認する --- */
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int dp[1000 + 1][(1 << 12)];

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), c(m, 0);
  rep(i, m) {
    int b;
    cin >> a[i] >> b;
    rep(j, b) {
      int _c;
      cin >> _c;
      c[i] |= (1 << (_c - 1));
    }
  }

  rep(i, m + 1) rep(j, (1 << n)) dp[i][j] = INF;
  dp[0][0] = 0;

  rep(i, m) rep(j, (1 << n)) if (dp[i][j] != INF) {
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    dp[i + 1][j | c[i]] = min(dp[i + 1][j | c[i]], dp[i][j] + a[i]);
  }

  int ans = dp[m][(1 << n) - 1];
  if (ans == INF) ans = -1;
  cout << ans << endl;
}
