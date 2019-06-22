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
  int H, W, N;
  cin >> H >> W >> N;

  map<pair<int, int>, int> cnt;

  rep (_, N) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int y = i + a;
        int x = j + b;
        if (0 < y && y < H - 1 && 0 < x && x < W - 1) {
          cnt[mp(y, x)]++;
        }
      }
    }
  }

  vector<ll> ans(10, 0);

  for (auto p : cnt) {
    ans[p.S]++;
  }

  ans[0] = 1LL * (H - 2) * (W - 2);
  REP (i, 1, 10) ans[0] -= ans[i];

  rep (i, 10) cout << ans[i] << endl;
}
