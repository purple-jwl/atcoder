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
  int N, C;
  cin >> N >> C;

  int D[C][C];
  rep (i, C) rep (j, C) cin >> D[i][j];

  int c[N][N];
  rep (i, N) rep (j, N) cin >> c[i][j];

  int sum[3][C];
  memset(sum, 0, sizeof(sum));
  rep (i, N) rep (j, N) rep (k, C) {
    int idx = (i + 1 + j + 1) % 3;
    sum[idx][k] += D[c[i][j] - 1][k];
  }

  int ans = INF;
  REP (i, 0, C) REP (j, i + 1, C) REP (k, j + 1, C) {
    rep (p, 3) rep (q, 3) rep (r, 3) if (p != q && q != r && r != p) {
      ans = min(ans, sum[p][i] + sum[q][j] + sum[r][k]);
    }
  }

  cout << ans << endl;
}
