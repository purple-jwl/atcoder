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

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  int c[12];
  int a[12][12];
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  int ans = 1 << 30;

  rep(i, (1 << n)) {
    vector<int> v(m, 0);
    int sum = 0;
    rep(j, n) if ((i >> j) & 1) {
      sum += c[j];
      rep(k, m) v[k] += a[j][k];
    }
    bool f = true;
    rep(j, m) if (v[j] < x) f = false;

    if (f) ans = min(ans, sum);
  }

  if (ans == (1 << 30)) ans = -1;

  cout << ans << endl;
}
