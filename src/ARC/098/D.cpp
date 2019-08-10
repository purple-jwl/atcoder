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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> bsum(20, vector<int>(n, 0));
  rep(i, 20) rep(j, n) {
    bsum[i][j] = (a[j] >> i) & 1;
    if (j > 0) bsum[i][j] += bsum[i][j - 1];
  }

  ll ans = 0;
  rep(i, n) {
    int r = n - 1;
    rep(j, 20) {
      int target = bsum[j][i] + ((a[i] >> j) & 1 ? 1 : 2);
      int k = lower_bound(all(bsum[j]), target) - bsum[j].begin() - 1;
      r = min(r, k);
    }
    ans += (r - i + 1);
  }

  cout << ans << endl;
}
