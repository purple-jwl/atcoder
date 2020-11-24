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
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int G[1500][1500];
int res[1500][1500];

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    G[a - 1][b - 1] = 1;
  }
  rep(i, M) {
    int c, d;
    cin >> c >> d;
    G[c - 1][d - 1] = -1;
  }

  int state;
  rep(i, H) {
    state = 0;
    for (int j = 0; j < W; j++) {
      if (G[i][j] == -1) state = 0;
      if (G[i][j] == 1) state = 1;
      if (state) res[i][j] = 1;
    }
    state = 0;
    for (int j = W - 1; j >= 0; j--) {
      if (G[i][j] == -1) state = 0;
      if (G[i][j] == 1) state = 1;
      if (state) res[i][j] = 1;
    }
  }

  rep(j, W) {
    state = 0;
    for (int i = 0; i < H; i++) {
      if (G[i][j] == -1) state = 0;
      if (G[i][j] == 1) state = 1;
      if (state) res[i][j] = 1;
    }
    state = 0;
    for (int i = H - 1; i >= 0; i--) {
      if (G[i][j] == -1) state = 0;
      if (G[i][j] == 1) state = 1;
      if (state) res[i][j] = 1;
    }
  }

  int ans = 0;
  rep(i, H) rep(j, W) ans += res[i][j];

  cout << ans << endl;
}
