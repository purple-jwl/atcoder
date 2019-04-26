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

const int INF = 1 << 29;
// const ll INF = 1LL << 62;
// const int MOD = 1000000007;

int main() {
  int N, M, R;
  cin >> N >> M >> R;

  vector<int> r(R);
  rep (i, R) {
    cin >> r[i];
    r[i]--;
  }

  int d[N][N];
  rep (i, N) rep (j, N) d[i][j] = (i == j) ? 0 : INF;

  rep (i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = d[b][a] = c;
  }

  rep (k, N) rep (i, N) rep (j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  sort(all(r));
  int ans = INF;

  do {
    int sum = 0;
    rep (i, R - 1) sum += d[r[i]][r[i + 1]];
    ans = min(ans, sum);
  } while (next_permutation(all(r)));

  cout << ans << endl;
}
