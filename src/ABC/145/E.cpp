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

int main() {
  const int T = 6000 + 1;
  int n, t;
  cin >> n >> t;
  vector<int> dp(T, -1);
  dp[0] = 0;

  vector<pii> ab(n);
  rep(i, n) cin >> ab[i].F >> ab[i].S;

  sort(all(ab));

  int ans = 0;
  rep(i, n) {
    int a = ab[i].F;
    int b = ab[i].S;
    for (int j = t - 1; j >= 0; j--) {
      if (dp[j] == -1) continue;
      dp[j + a] = max(dp[j + a], dp[j] + b);
      ans = max(dp[j + a], ans);
    }
  }

  cout << ans << endl;
}
