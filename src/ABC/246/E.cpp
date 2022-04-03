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
  int n;
  cin >> n;
  int ar, ac, br, bc;
  cin >> ar >> ac >> br >> bc;
  ar--;
  ac--;
  br--;
  bc--;

  char board[n][n];
  rep(i, n) rep(j, n) cin >> board[i][j];

  int dr[] = {1, 1, -1, -1};
  int dc[] = {1, -1, 1, -1};

  int dist[n][n][4];
  rep(i, n) rep(j, n) rep(k, 4) dist[i][j][k] = INF;

  deque<pair<pii, int>> Q;
  Q.push_back(mp(mp(ar, ac), -1));
  rep(k, 4) dist[ar][ac][k] = 0;

  while (!Q.empty()) {
    pii p = Q.front().F;
    int dir = Q.front().S;
    Q.pop_front();

    if (p.F == br && p.S == bc) {
      cout << dist[p.F][p.S][dir] << endl;
      return 0;
    }

    rep(i, 4) {
      int nr = p.F + dr[i];
      int nc = p.S + dc[i];
      int d = (dir == -1) ? 0 : dist[p.F][p.S][dir];
      if (dir != i) d++;

      if (!(0 <= nr && nr < n && 0 <= nc && nc < n)) continue;
      if (board[nr][nc] == '#') continue;
      if (dist[nr][nc][i] <= d) continue;
      dist[nr][nc][i] = d;
      if (dir != i)
        Q.push_back(mp(mp(nr, nc), i));
      else
        Q.push_front(mp(mp(nr, nc), i));
    }
  }

  cout << -1 << endl;
}
