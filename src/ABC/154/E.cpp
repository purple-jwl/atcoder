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

ll dp[101][2][5];

int main() {
  string N;
  cin >> N;
  int K;
  cin >> K;

  dp[0][0][0] = 1;

  rep(i, N.size()) rep(ls, 2) rep(k, K + 1) if (dp[i][ls][k] != 0) {
    int v = N[i] - '0';
    int limit = ls ? 9 : v;
    rep(p, limit + 1) {
      int nls = ls || p != v;
      int nk = k + (p != 0);
      dp[i + 1][nls][nk] += dp[i][ls][k];
    }
  }

  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
}
