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
  ll n;
  cin >> n;

  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": " << n / i << ' ' << n % i << (n / i == n % i ? "**" :
  //   "")
  //        << endl;
  // }

  set<ll> sl;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sl.insert(i - 1);
      sl.insert(n / i - 1);
    }
  }

  ll ans = 0;
  for (auto it = sl.begin(); it != sl.end(); it++) {
    ll v = *it;
    if (v == 0) continue;
    if (n / v == n % v) ans += v;
  }

  cout << ans << endl;
}
