#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  char c[h][w];
  rep(i, h) rep(j, w) cin >> c[i][j];

  int n = min(h, w);
  vector<int> ans(n, 0);

  int dx[] = {1, -1, -1, 1};
  int dy[] = {-1, 1, -1, 1};
  rep(i, h) rep(j, w) if (c[i][j] == '#') {
    REP(d, 1, n) {
      bool f = true;
      rep(k, 4) {
        int nx = i + dx[k] * d;
        int ny = j + dy[k] * d;
        if (!(0 <= nx && nx < h))
          f = false;
        else if (!(0 <= ny && ny < w))
          f = false;
        else if (c[nx][ny] != '#')
          f = false;
      }
      if (!f) {
        if (d > 1) ans[d - 2]++;
        break;
      }
    }
  }

  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}
