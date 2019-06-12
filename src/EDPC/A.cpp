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

const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep (i, n) cin >> h[i];

  vector<int> dp(n, INF);
  dp[0] = 0;

  rep (i, n) {
    if (i - 1 >= 0) dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;
}
