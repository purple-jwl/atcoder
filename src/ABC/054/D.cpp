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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int dp[401][401];

int main() {
  rep (i, 401) rep (j, 401) dp[i][j] = INF;
  dp[0][0] = 0;

  int n, ma, mb;
  cin >> n >> ma >> mb;

  rep (i, n) {
    int a, b, c;
    cin >> a >> b >> c;

    for (int j = 400; j >= 0; j--) {
      for (int k = 400; k >= 0; k--) {
        if (j + a > 400 || k + b > 400 || dp[j][k] == INF) continue;
        dp[j + a][k + b] = min(dp[j + a][k + b], dp[j][k] + c);
      }
    }
  }

  int ans = INF;
  for (int i = 1; ; i++) {
    if (ma * i > 400 || mb * i > 400) break;
    ans = min(ans, dp[ma * i][mb * i]);
  }

  if (ans == INF) ans = -1;

  cout << ans << endl;
}
