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
// const ll MOD = 1000000007;

bool dp[81][81][160 * 80];
int a[80][80], b[80][80];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];

  memset(dp, false, sizeof(dp));
  dp[0][0][0] = 1;

  rep(i, h) rep(j, w) {
    int v = abs(a[i][j] - b[i][j]);
    rep(k, (h + w) * 80) if (dp[i][j][k]) {
      dp[i + 1][j][k + v] = dp[i + 1][j][abs(k - v)] = 1;
      dp[i][j + 1][k + v] = dp[i][j + 1][abs(k - v)] = 1;
    }
  }

  rep(k, 160 * 80) if (dp[h - 1][w][k] || dp[h][w - 1][k]) {
    cout << k << endl;
    return 0;
  }
}
