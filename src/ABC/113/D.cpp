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

const int mod = 1000000007;

bool ok(int b, int w) {
  rep (i, w - 1) if (((1 << i) & b) != 0 && ((1 << (i + 1)) & b) != 0) return false;
  return true;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  int dp[H + 1][W + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  rep (h, H) rep (w, W) rep (i, (1 << (W - 1))) if (dp[h][w] != 0 && ok(i, W - 1)) {
    if (w != 0 && (1 << (w - 1)) & i) dp[h + 1][w - 1] = (dp[h + 1][w - 1] + dp[h][w]) % mod;
    else if (w != W - 1 && (1 << w) & i) dp[h + 1][w + 1] = (dp[h + 1][w + 1] + dp[h][w]) % mod;
    else dp[h + 1][w] = (dp[h + 1][w] + dp[h][w]) % mod;
  }

  cout << dp[H][K - 1] << endl;
}
