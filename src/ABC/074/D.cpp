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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> A[i][j];

  vector<vector<int>> dp = A;
  rep(k, n) rep(i, n) rep(j, n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  bool f = true;
  rep(i, n) rep(j, n) if (A[i][j] != dp[i][j]) f = false;

  if (!f) {
    cout << "-1" << endl;
    return 0;
  }

  ll ans = 0;
  rep(i, n) rep(j, n) if (i < j) {
    f = true;
    rep(k, n) if (i != k && j != k && A[i][j] == A[i][k] + A[k][j]) f = false;
    if (f) ans += A[i][j];
  }

  cout << ans << endl;
}
