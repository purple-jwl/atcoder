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
// const int MOD = 1000000007;

ll dp[100001];

int main() {
  int N, W;
  cin >> N >> W;

  rep (i, W + 1) dp[i] = -1;
  dp[0] = 0;

  rep (i, N) {
    int w, v;
    cin >> w >> v;
    for (int j = W - w; j >= 0; j--) {
      if (dp[j] == -1) continue;
      dp[j + w] = max(dp[j + w], dp[j] + v);
    }
  }

  ll ans = 0;
  rep (i, W + 1) ans = max(ans, dp[i]);

  cout << ans << endl;
}
