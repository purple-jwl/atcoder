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
  vector<int> a(n + 1), b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 0;
  rep(i, n) {
    if (b[i] > a[i]) {
      ans += a[i];
      b[i] -= a[i];
      if (b[i] > a[i + 1]) {
        ans += a[i + 1];
        a[i + 1] = 0;
      } else {
        ans += b[i];
        a[i + 1] -= b[i];
      }
    } else {
      ans += b[i];
    }
  }

  cout << ans << endl;
}
