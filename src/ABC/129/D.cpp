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

int H, W;
char board[2000][2000];
int lsum[2000][2000], rsum[2000][2000], usum[2000][2000], dsum[2000][2000];

int main() {
  cin >> H >> W;
  rep (i, H) rep (j, W) cin >> board[i][j];

  rep (i, H) {
    for (int j = 0; j < W; j++) {
      if (board[i][j] == '.') {
        if (j - 1 >= 0) lsum[i][j] = lsum[i][j - 1] + 1;
        else lsum[i][j] = 1;
      }
    }
    for (int j = W - 1; j >= 0; j--) {
      if (board[i][j] == '.') {
        if (j + 1 < W) rsum[i][j] = rsum[i][j + 1] + 1;
        else rsum[i][j] = 1;
      }
    }
  }

  rep (j, W) {
    for (int i = 0; i < H; i++) {
      if (board[i][j] == '.') {
        if (i - 1 >= 0) usum[i][j] = usum[i - 1][j] + 1;
        else usum[i][j] = 1;
      }
    }
    for (int i = H - 1; i >= 0; i--) {
      if (board[i][j] == '.') {
        if (i + 1 < H) dsum[i][j] = dsum[i + 1][j] + 1;
        else dsum[i][j] = 1;
      }
    }
  }

  int ans = 0;
  rep (i, H) rep (j, W) if (board[i][j] == '.') {
    ans = max(ans, lsum[i][j] + rsum[i][j] + dsum[i][j] + usum[i][j] - 3);
  }

  cout << ans << endl;
}
