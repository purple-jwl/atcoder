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

ll dp[1000001][2][2];

int main() {
  int n;
  cin >> n;
  dp[0][0][0] = 1;

  rep(i, n) rep(j, 2) rep(k, 2) if (dp[i][j][k]) {
    rep(d, 10) {
      dp[i + 1][j | (d == 0)][k | (d == 9)] += dp[i][j][k];
      dp[i + 1][j | (d == 0)][k | (d == 9)] %= MOD;
    }
  }

  cout << dp[n][1][1] << endl;
}
