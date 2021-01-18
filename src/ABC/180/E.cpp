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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int cost[1 << 17][17];

int main() {
  int n;
  cin >> n;

  vector<int> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];

  queue<pii> Q;
  Q.push(mp(1, 0));

  rep(i, (1 << n)) rep(j, n) cost[i][j] = INF;
  cost[1][0] = 0;

  // while (!Q.empty()) {
  //   pii p = Q.front();
  //   Q.pop();

  //   rep(i, n) {
  //     if ((p.F >> i) & 1) continue;
  //     int c = abs(x[i] - x[p.S]) + abs(y[i] - y[p.S]) + max(0, z[i] -
  //     z[p.S]); int next = p.F | (1 << i); if (cost[next][i] > cost[p.F][p.S]
  //     + c) {
  //       cost[next][i] = cost[p.F][p.S] + c;
  //       Q.push(mp(next, i));
  //     }
  //   }
  // }

  rep(i, (1 << n)) rep(j, n) if ((i >> j) & 1) {
    rep(k, n) if (!((i >> k) & 1)) {
      int next = i | (1 << k);
      cost[next][k] =
          min(cost[next][k], cost[i][j] + abs(x[k] - x[j]) + abs(y[k] - y[j]) +
                                 max(0, z[k] - z[j]));
    }
  }

  int ans = INF;

  REP(i, 1, n) {
    int c = abs(x[0] - x[i]) + abs(y[0] - y[i]) + max(0, z[0] - z[i]);
    ans = min(ans, cost[(1 << n) - 1][i] + c);
  }

  cout << ans << endl;
}
