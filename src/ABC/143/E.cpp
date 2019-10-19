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
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

ll d[300][300];
ll ans[300][300];

int main() {
  int N, M, L;
  cin >> N >> M >> L;

  rep(i, N) rep(j, N) {
    d[i][j] = INF;
    ans[i][j] = INF;
  }

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a - 1][b - 1] = d[b - 1][a - 1] = c;

    if (c <= L) {
      ans[a - 1][b - 1] = ans[b - 1][a - 1] = 0;
    }
  }

  rep(k, N) rep(i, N) rep(j, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }

  rep(i, N) rep(j, N) if (d[i][j] <= L) ans[i][j] = 0;

  rep(k, N) rep(i, N) rep(j, N) {
    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j] + 1);
  }

  int Q;
  cin >> Q;
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (ans[s][t] == INF)
      cout << "-1" << endl;
    else
      cout << ans[s][t] << endl;
  }
}
