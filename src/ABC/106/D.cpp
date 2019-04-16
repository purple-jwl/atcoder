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

int dp[500][500];

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  rep (i, M) {
    int L, R;
    cin >> L >> R;
    dp[L - 1][R - 1]++;
  }

  rep (i, N) rep (j, N) {
    if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
    if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
    if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] -= dp[i - 1][j - 1];
  }

  rep (i, Q) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    int ans = dp[q][q];
    if (p - 1 >= 0) {
      ans -= dp[p - 1][q];
      ans -= dp[q][p - 1];
      ans += dp[p - 1][p - 1];
    }
    cout << ans << endl;
  }
}
