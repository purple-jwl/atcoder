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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dist[1000][1000];
char a[1000][1000];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];

  queue<pii> q;
  rep(i, h) rep(j, w) {
    if (a[i][j] == '#') {
      dist[i][j] = 0;
      q.push(mp(i, j));
    } else {
      dist[i][j] = INF;
    }
  }

  int ans = 0;
  while (!q.empty()) {
    int y = q.front().F;
    int x = q.front().S;
    q.pop();

    rep(i, 4) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (!(0 <= nx && nx < w && 0 <= ny && ny < h)) continue;
      if (dist[ny][nx] <= dist[y][x] + 1) continue;
      dist[ny][nx] = dist[y][x] + 1;
      ans = max(dist[ny][nx], ans);
      q.push(mp(ny, nx));
    }
  }

  cout << ans << endl;
}
