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

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

double dp[40000 + 1][200 + 1];

int main() {
  int n;
  cin >> n;

  vector<int> t(n), v(n);
  rep (i, n) cin >> t[i];
  rep (i, n) cin >> v[i];

  int tt = 0;
  rep (i, 40001) rep (j, 201) dp[i][j] = -1;
  dp[0][0] = 0;

  rep (i, n) rep (j, t[i] * 2) {
    rep (k, v[i] * 2 + 1) if (dp[tt][k] != -1) {
      dp[tt + 1][k] = max(dp[tt + 1][k], dp[tt][k] + (k / 2.0 + k / 2.0) / 4);
      if (k + 1 <= v[i] * 2) {
        dp[tt + 1][k + 1] = max(dp[tt + 1][k + 1], dp[tt][k] + (k / 2.0 + (k + 1) / 2.0) / 4);
      }
      if (k - 1 >= 0) {
        dp[tt + 1][k - 1] = max(dp[tt + 1][k - 1], dp[tt][k] + (k / 2.0 + (k - 1) / 2.0) / 4);
      }
    }
    tt++;
  }

  printf("%.10f\n", dp[tt][0]);
}
