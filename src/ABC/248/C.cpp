#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
const ll MOD = 998244353;

ll dp[50 + 1][2500 + 1];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  dp[0][0] = 1;

  rep(i, n) rep(j, n * m + 1) if (dp[i][j] != 0) {
    int next = 1;
    while (next <= m) {
      dp[i + 1][j + next] += dp[i][j];
      dp[i + 1][j + next] %= MOD;
      next++;
    }
  }

  ll ans = 0;
  rep(i, k + 1) {
    ans += dp[n][i];
    ans %= MOD;
  }

  cout << ans << endl;
}
