#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  bool dp[n][2];
  memset(dp, false, sizeof(dp));
  dp[0][0] = dp[0][1] = 1;

  rep(i, n - 1) {
    if (dp[i][0]) {
      if (abs(a[i + 1] - a[i]) <= k) dp[i + 1][0] = 1;
      if (abs(b[i + 1] - a[i]) <= k) dp[i + 1][1] = 1;
    }
    if (dp[i][1]) {
      if (abs(a[i + 1] - b[i]) <= k) dp[i + 1][0] = 1;
      if (abs(b[i + 1] - b[i]) <= k) dp[i + 1][1] = 1;
    }
  }

  cout << ((dp[n - 1][0] || dp[n - 1][1]) ? "Yes" : "No") << endl;
}
