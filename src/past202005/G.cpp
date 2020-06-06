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

int dx[] = {1, 0, -1, 1, -1, 0};
int dy[] = {1, 1, 1, 0, 0, -1};

int MAX = 2000;

int dist[2000][2000];
bool G[2000][2000];

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;

  X += 1000;
  Y += 1000;

  rep(i, N) {
    int x, y;
    cin >> x >> y;
    x += 1000;
    y += 1000;
    G[y][x] = 1;
  }

  rep(i, MAX) rep(j, MAX) dist[i][j] = INF;
  dist[1000][1000] = 0;

  queue<pii> Q;
  Q.push(mp(1000, 1000));

  while (!Q.empty()) {
    int x = Q.front().F;
    int y = Q.front().S;
    //    cout << x << ' ' << y << endl;
    Q.pop();

    rep(i, 6) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!(0 <= nx && nx < MAX)) continue;
      if (!(0 <= ny && ny < MAX)) continue;
      if (G[ny][nx]) continue;
      if (dist[y][x] + 1 < dist[ny][nx]) {
        dist[ny][nx] = dist[y][x] + 1;
        if (ny == Y && nx == X) {
          cout << dist[ny][nx] << endl;
          return 0;
        }
        Q.push(mp(nx, ny));
      }
    }
  }

  cout << -1 << endl;
}
