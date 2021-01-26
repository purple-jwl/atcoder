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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int H, W;
char a[2000][2000];
int cost[2000][2000];
bool visited[26];
vector<pii> pos[26];

int solve(int sx, int sy, int gx, int gy) {
  queue<pii> Q;
  Q.push(mp(sx, sy));

  rep(y, H) rep(x, W) cost[y][x] = INF;
  cost[sy][sx] = 0;

  while (!Q.empty()) {
    int x = Q.front().F;
    int y = Q.front().S;
    Q.pop();

    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!(0 <= nx && nx < W)) continue;
      if (!(0 <= ny && ny < H)) continue;
      if (a[ny][nx] == '#') continue;
      if (cost[ny][nx] > cost[y][x] + 1) {
        cost[ny][nx] = cost[y][x] + 1;

        Q.push(mp(nx, ny));

        if ('a' <= a[ny][nx] && a[ny][nx] <= 'z' && !visited[a[ny][nx] - 'a']) {
          int key = a[ny][nx] - 'a';
          visited[key] = 1;

          rep(j, pos[key].size()) {
            int nnx = pos[key][j].F;
            int nny = pos[key][j].S;

            if (cost[nny][nnx] > cost[ny][nx] + 1) {
              cost[nny][nnx] = cost[ny][nx] + 1;
              Q.push(mp(nnx, nny));
            }
          }
        }
      }
    }
  }

  return cost[gy][gx] == INF ? -1 : cost[gy][gx];
}

int main() {
  cin >> H >> W;
  int sx, sy, gx, gy;
  rep(i, H) rep(j, W) {
    cin >> a[i][j];
    if ('a' <= a[i][j] && a[i][j] <= 'z') pos[a[i][j] - 'a'].eb(mp(j, i));
    if (a[i][j] == 'S') sy = i, sx = j;
    if (a[i][j] == 'G') gy = i, gx = j;
  }
  cout << solve(sx, sy, gx, gy) << endl;
}
