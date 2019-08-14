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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

const int N = 100;
char grid[N][N];

// . = write, # = black
int main() {
  int a, b;
  cin >> a >> b;

  rep(i, N) rep(j, N) grid[i][j] = '#';
  rep(i, N / 2) rep(j, N) grid[i][j] = '.';

  for (int i = 0; i < N / 2; i += 2) {
    for (int j = 0; j < N; j += 2) {
      if (b > 1) {
        grid[i][j] = '#';
        b--;
      }
    }
  }

  for (int i = N / 2 + 1; i < N; i += 2) {
    for (int j = 0; j < N; j += 2) {
      if (a > 1) {
        grid[i][j] = '.';
        a--;
      }
    }
  }

  cout << "100 100" << endl;
  rep(i, N) {
    rep(j, N) cout << grid[i][j];
    cout << endl;
  }
}
