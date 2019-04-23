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

const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
  int H, W;
  cin >> H >> W;

  char s[H][W];
  rep (i, H) rep (j, W) cin >> s[i][j];

  int minDist[H][W];
  rep (i, H) rep (j, W) minDist[i][j] = INF;
  minDist[0][0] = 1;
  queue<pair<int, int>> Q;
  Q.push(mp(0, 0));

  while(!Q.empty()) {
    int x = Q.front().F;
    int y = Q.front().S;
    Q.pop();

    rep (i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!(0 <= nx && nx < W && 0 <= ny && ny < H)) continue;
      if (s[ny][nx] == '#') continue;
      if (minDist[ny][nx] <= minDist[y][x] + 1) continue;
      minDist[ny][nx] = minDist[y][x] + 1;
      Q.push(mp(nx, ny));
    }
  }

  int bCnt = 0;
  rep (i, H) rep (j, W) if (s[i][j] == '#') bCnt++;

  if (minDist[H - 1][W - 1] == INF) cout << "-1" << endl;
  else cout << H * W - bCnt - minDist[H - 1][W - 1] << endl;
}
