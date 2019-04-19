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

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> x(n), y(n), z(n);
  rep (i, n) cin >> x[i] >> y[i] >> z[i];

  ll ans = 0;
  rep (bit, (1 << 3)) {
    vector<ll> sum;
    rep (i, n) {
      ll tmp = 0;
      tmp += x[i] * (bit & 1 ? -1 : 1);
      tmp += y[i] * (bit & 2 ? -1 : 1);
      tmp += z[i] * (bit & 4 ? -1 : 1);
      sum.eb(tmp);
    }

    sort(rall(sum));

    ll v = 0;
    rep (i, m) v += sum[i];

    ans = max(ans, v);
  }

  cout << ans << endl;
}
