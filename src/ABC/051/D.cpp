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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<pair<int, int>> edge[100];
int dist[100][100];

int main() {
  int N, M;
  cin >> N >> M;

  rep (i, N) rep (j, N) dist[i][j] = (i == j) ? 0 : INF;

  rep (i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge[a].eb(mp(b, c));
    edge[b].eb(mp(a, c));
    dist[a][b] = dist[b][a] = c;
  }

  rep (k, N) rep (i, N) rep (j, N) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }

  int ans = 0;
  rep (i, N) rep (j, edge[i].size()) {
    int from = i;
    int to = edge[i][j].F;
    int d = edge[i][j].S;

    bool flg = true;
    rep (p, N) rep (q, N) if (dist[p][q] == dist[p][from] + d + dist[to][q]) flg = false;

    if (flg) ans++;
  }

  cout << ans / 2 << endl;
}
