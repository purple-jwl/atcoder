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
  int H, W;
  cin >> H >> W;

  int N;
  cin >> N;

  queue<int> Q;
  rep (i, N) {
    int a;
    cin >> a;
    rep (j, a) Q.push(i + 1);
  }

  int c[H][W];

  rep (i, H) {
    if (i % 2) {
      for (int j = W - 1; j >= 0; j--) {
        c[i][j] = Q.front();
        Q.pop();
      }
    } else {
      rep (j, W) {
        c[i][j] = Q.front();
        Q.pop();
      }
    }
  }

  rep (i, H) {
    rep (j, W) cout << (j == 0 ? "" : " ") << c[i][j];
    cout << endl;
  }
}
