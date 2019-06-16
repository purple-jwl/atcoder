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

ll dp[2005][2005];

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> S(N + 1), T(M + 1);
  S[0] = T[0] = 0;
  rep (i, N) cin >> S[i + 1];
  rep (i, M) cin >> T[i + 1];

  dp[0][0] = 1;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i + j == 0) continue;
      if (S[i] == T[j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      else {
        if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        if (i > 0 && j > 0) dp[i][j] = (dp[i][j] + MOD - dp[i - 1][j - 1]) % MOD;
      }
    }
  }

  cout << dp[N][M] << endl;
}
