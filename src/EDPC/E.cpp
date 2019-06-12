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
const ll INF = 1LL << 60;
// const int MOD = 1000000007;

const int M = 100000 + 5;
ll dp[M];

int main() {
  int N, W;
  cin >> N >> W;

  rep (i, M) dp[i] = INF;
  dp[0] = 0;

  rep (i, N) {
    int w, v;
    cin >> w >> v;

    for (int j = M - v - 1; j >= 0; j--) {
      if (dp[j] == INF) continue;
      dp[j + v] = min(dp[j + v], dp[j] + w);
    }
  }

  for (int j = M - 1; j >= 0; j--) {
    if (dp[j] <= W) {
      cout << j << endl;
      return 0;
    }
  }
}
