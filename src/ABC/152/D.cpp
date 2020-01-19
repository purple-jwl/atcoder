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

int memo[10][10];

int main() {
  int n;
  cin >> n;

  REP(i, 1, 10) REP(j, 1, 10) {
    int cnt = 0;
    rep(k, n + 1) {
      if (k % 10 == 0) continue;
      int a = k % 10;
      int b = k;
      while (b >= 10) b /= 10;
      if (i == b && j == a) cnt++;
    }
    memo[i][j] = cnt;
  }

  ll ans = 0;
  rep(i, n + 1) {
    if (i % 10 == 0) continue;
    int a = i % 10;
    int b = i;
    while (b >= 10) b /= 10;
    ans += memo[a][b];
  }

  cout << ans << endl;
}
