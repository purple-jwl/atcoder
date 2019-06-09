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
const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> dp(n + 1, 0);
  rep (i, m) {
    int a;
    cin >> a;
    dp[a] = -1;
  }

  dp[0] = 1;
  rep (i, n) {
    if (dp[i] == -1) continue;
    if (i + 1 <= n && dp[i + 1] != -1) dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    if (i + 2 <= n && dp[i + 2] != -1) dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
  }

  cout << dp[n] << endl;
}
