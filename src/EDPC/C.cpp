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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> abc(n, vector<int>(3));
  rep (i, n) rep (j, 3) cin >> abc[i][j];

  vector<vector<int>> dp(n, vector<int>(3, 0));
  rep (i, n) rep (j, 3) {
    if (i == 0) dp[i][j] = abc[i][j];
    else {
      rep (k, 3) {
        if (j == k) continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + abc[i][j]);
      }
    }
  }

  int ans = 0;
  rep (i, 3) ans = max(ans, dp[n - 1][i]);

  cout << ans << endl;
}
