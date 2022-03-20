#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
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

ll dp[2000][2][2];

int main() {
  int N, M, K, S, T, X;
  cin >> N >> M >> K >> S >> T >> X;
  S--;
  T--;
  X--;

  vector<int> edge[N];
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].eb(v);
    edge[v].eb(u);
  }

  dp[S][0][0] = 1;

  rep(k, K + 1) {
    int cur = k % 2;
    int next = (k + 1) % 2;

    rep(i, N) rep(j, 2) dp[i][j][next] = 0;

    rep(i, N) rep(j, 2) if (dp[i][j][cur] != 0) {
      rep(x, edge[i].size()) {
        int y = j;
        if (edge[i][x] == X) y = (y + 1) % 2;
        dp[edge[i][x]][y][next] += dp[i][j][cur];
        dp[edge[i][x]][y][next] %= MOD;
      }
    }
  }

  cout << dp[T][0][K % 2] << endl;
}
