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
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
const ll MOD = 1000000007;

char s[2000][2000];
ll dp[2000][2000], x[2000][2000], y[2000][2000], xy[2000][2000];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> s[i][j];

  dp[0][0] = 1;

  rep(i, h) rep(j, w) if (s[i][j] == '.') {
    if (i - 1 >= 0 && j - 1 >= 0) {
      xy[i][j] = (dp[i - 1][j - 1] + xy[i - 1][j - 1]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + xy[i - 1][j - 1]) % MOD;
    }
    if (i - 1 >= 0) {
      y[i][j] = (dp[i - 1][j] + y[i - 1][j]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i - 1][j] + y[i - 1][j]) % MOD;
    }
    if (j - 1 >= 0) {
      x[i][j] = (dp[i][j - 1] + x[i][j - 1]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i][j - 1] + x[i][j - 1]) % MOD;
    }
  }

  cout << dp[h - 1][w - 1] << endl;
}
