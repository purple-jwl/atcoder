#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> edge[n];
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].eb(v);
    edge[v].eb(u);
  }

  int dist[1 << n][n];

  rep(i, 1 << n) rep(j, n) dist[i][j] = INF;
  rep(i, n) dist[0][i] = 0;

  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int p = Q.front();
    Q.pop();

    rep(i, n) if (dist[p][i] != INF) {
      rep(j, edge[i].size()) {
        int next = edge[i][j];
        if (dist[p][i] + 1 < dist[p ^ (1 << next)][next]) {
          dist[p ^ (1 << next)][next] = dist[p][i] + 1;
          Q.push(p ^ (1 << next));
        }
      }
    }
  }

  int ans = 0;
  rep(i, 1 << n) {
    int v = INF;
    rep(j, n) v = min(v, dist[i][j]);
    ans += v;
  }

  cout << ans << endl;
}
