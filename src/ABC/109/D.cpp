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

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int h, w;
  cin >> h >> w;

  int a[500][500];
  rep (i, h) rep (j, w) cin >> a[i][j];

  vector<pair<pair<int, int>, pair<int, int>>> vp;
  rep (i, h) rep (j, w) {
    if (i == h - 1 && j == w - 1) continue;

    int y, x, ny, nx;

    if (i % 2 == 0) {
      ny = y = i;
      nx = x = j;
      if (++nx == w) {
        nx--;
        ny++;
      }
    } else {
      ny = y = i;
      nx = x = w - 1 - j;
      if (--nx == -1) {
        nx++;
        ny++;
      }
    }

    if (a[y][x] % 2) {
      a[y][x]--;
      a[ny][nx]++;
      vp.eb(mp(mp(y + 1, x + 1), mp(ny + 1, nx + 1)));
    }
  }

  cout << sz(vp) << endl;
  rep (i, sz(vp)) {
    cout << vp[i].F.F << ' ' << vp[i].F.S << ' ' << vp[i].S.F << ' ' << vp[i].S.S << endl;
  }
}
