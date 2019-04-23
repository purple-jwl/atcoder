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
  int H, W, D;
  cin >> H >> W >> D;

  int A[H][W];
  pair<int, int> p[H * W + 1];
  rep (i, H) rep (j, W) {
    cin >> A[i][j];
    p[A[i][j]] = mp(i, j);
  }

  int power[H * W + 1];
  memset(power, 0, sizeof(power));
  REP (i, 1, H * W - D + 1) {
    power[i + D] = power[i] + abs(p[i].F - p[i + D].F) + abs(p[i].S - p[i + D].S);
  }

  int Q;
  cin >> Q;
  rep (i, Q) {
    int L, R;
    cin >> L >> R;
    cout << power[R] - power[L] << endl;
  }
}
