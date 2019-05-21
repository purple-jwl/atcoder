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

int main() {
  int N, W;
  cin >> N >> W;

  vector<int> vv[4];
  ll w1;

  rep (i, N) {
    int w, v;
    cin >> w >> v;
    if (i == 0) w1 = w;
    vv[w - w1].eb(v);
  }

  vector<int> sum[4];
  rep (i, 4) {
    sort(rall(vv[i]));
    sum[i].eb(0);
    rep (j, vv[i].size()) {
      sum[i].eb(sum[i].back() + vv[i][j]);
    }
  }

  int ans = 0;
  rep (i, sum[0].size()) rep (j, sum[1].size()) rep (k, sum[2].size()) rep (l, sum[3].size()) {
    ll w = w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l;
    if (w > W) continue;
    ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
  }

  cout << ans << endl;
}
