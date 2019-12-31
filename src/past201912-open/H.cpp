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
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> c(n);
  rep(i, n) cin >> c[i];

  ll odd_minv = c[0];
  ll even_minv = (n != 1) ? c[1] : INF;
  rep(i, n) {
    if (i % 2) even_minv = min(even_minv, c[i]);
    if (i % 2 == 0) odd_minv = min(odd_minv, c[i]);
  }

  ll ans = 0;
  ll odd_used = 0;
  ll even_used = 0;
  int q;
  cin >> q;
  rep(i, q) {
    int op;
    cin >> op;

    if (op == 1) {
      int x, a;
      cin >> x >> a;
      x--;
      if (x % 2 && c[x] - even_used - a >= 0) {
        c[x] -= a;
        ans += a;
        even_minv = min(even_minv, c[x]);
      }
      if (x % 2 == 0 && c[x] - odd_used - a >= 0) {
        c[x] -= a;
        ans += a;
        odd_minv = min(odd_minv, c[x]);
      }
    }
    if (op == 2) {
      int a;
      cin >> a;
      if (odd_minv - odd_used - a >= 0) {
        odd_used += a;
      }
    }
    if (op == 3) {
      int a;
      cin >> a;
      if (min(odd_minv - odd_used, even_minv - even_used) - a >= 0) {
        odd_used += a;
        even_used += a;
      }
    }
  }

  ans += odd_used * ((n + 1) / 2);
  ans += even_used * (n / 2);

  cout << ans << endl;
}
