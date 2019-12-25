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

ll dp[50 + 1][2500 + 1];

int main() {
  int n, a;
  cin >> n >> a;
  dp[0][0] = 1;
  rep(i, n) {
    int x;
    cin >> x;
    for (int j = n; j >= 0; j--) {
      rep(k, 2500) if (dp[j][k] > 0) dp[j + 1][k + x] += dp[j][k];
    }
  }
  ll ans = 0;
  REP(i, 1, n + 1) REP(j, 1, 2501) {
    if (j % i == 0 && j / i == a) ans += dp[i][j];
  }
  cout << ans << endl;
}
