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
int A[50][50];
int dist[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int func(int y, int x) {
  rep(i, H) rep(j, W) dist[i][j] = INF;
  dist[y][x] = 0;
  queue<pii> Q;
  Q.push(mp(x, y));

  while (!Q.empty()) {
    int x = Q.front().F;
    int y = Q.front().S;
    Q.pop();
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
      if (dist[ny][nx] <= dist[y][x] + A[ny][nx]) continue;
      dist[ny][nx] = dist[y][x] + A[ny][nx];
      Q.push(mp(nx, ny));
    }
  }

  return A[y][x] + dist[0][W - 1] + dist[H - 1][W - 1] + dist[H - 1][0];
}

int main() {
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> A[i][j];
  int ans = INF;
  rep(i, H) rep(j, W) ans = min(ans, func(i, j));
  cout << ans << endl;
}
