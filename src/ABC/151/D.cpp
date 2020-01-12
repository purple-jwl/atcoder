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

int H, W;
char G[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int cost[20][20];

int f(int sy, int sx, int gy, int gx) {
  rep(i, H) rep(j, W) cost[i][j] = INF;
  cost[sy][sx] = 0;
  queue<pii> Q;
  Q.push(mp(sx, sy));

  while (!Q.empty()) {
    int x = Q.front().F;
    int y = Q.front().S;
    Q.pop();

    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!(0 <= nx && nx < W && 0 <= ny && ny < H)) continue;
      if (G[ny][nx] == '#') continue;
      if (cost[ny][nx] <= cost[y][x] + 1) continue;
      cost[ny][nx] = cost[y][x] + 1;
      if (nx == gx && ny == gy) return cost[ny][nx];
      Q.push(mp(nx, ny));
    }
  }

  return -1;
}

int main() {
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> G[i][j];

  int ans = 0;
  rep(i, H) rep(j, W) rep(p, H) rep(q, W) {
    if (G[i][j] == '.' && G[p][q] == '.') ans = max(ans, f(i, j, p, q));
  }

  cout << ans << endl;
}
