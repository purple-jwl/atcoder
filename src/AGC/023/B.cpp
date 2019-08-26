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

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  rep(i, n) cin >> vs[i];

  int ans = 0;
  rep(k, n) {
    bool f = true;
    rep(i, n) REP(j, i, n) {
      int y = i;
      int x = (j + k) % n;
      int ny = j;
      int nx = (i + k) % n;
      if (vs[y][x] != vs[ny][nx]) f = false;
    }
    if (f) ans++;
  }

  cout << ans * n << endl;
}
