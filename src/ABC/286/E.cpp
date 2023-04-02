#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

const int INF = 1 << 29;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int dist[n][n];
  ll val[n][n];
  rep(i, n) rep(j, n) dist[i][j] = INF, val[i][j] = 0;
  rep(i, n) dist[i][i] = 0, val[i][i] = 0;
  rep(i, n) rep(j, n) {
    char c;
    cin >> c;
    if (c == 'Y') dist[i][j] = 1, val[i][j] = a[j];
  }

  rep(k, n) rep(i, n) rep(j, n) {
    if (dist[i][j] > dist[i][k] + dist[k][j]) {
      dist[i][j] = dist[i][k] + dist[k][j];
      val[i][j] = val[i][k] + val[k][j];
    }
    if (dist[i][j] == dist[i][k] + dist[k][j] &&
        val[i][j] < val[i][k] + val[k][j]) {
      val[i][j] = val[i][k] + val[k][j];
    }
  }

  int q;
  cin >> q;
  rep(_, q) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    if (dist[u][v] == INF)
      cout << "Impossible" << endl;
    else
      cout << dist[u][v] << ' ' << val[u][v] + a[u] << endl;
  }
}
