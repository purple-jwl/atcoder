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

const ll INF = 1LL << 60;

int main() {
  int A, B, Q;
  cin >> A >> B >> Q;

  vector<ll> s(A), t(B);
  rep (i, A) cin >> s[i];
  rep (i, B) cin >> t[i];

  sort(all(s));
  sort(all(t));

  rep (i, Q) {
    ll x;
    cin >> x;

    vector<ll> ss, tt;
    int p;
    p = lower_bound(all(s), x) - s.begin();
    if (p != sz(s)) ss.eb(s[p]);
    if (p != 0) ss.eb(s[p - 1]);
    p = lower_bound(all(t), x) - t.begin();
    if (p != sz(t)) tt.eb(t[p]);
    if (p != 0) tt.eb(t[p - 1]);

    ll ans = INF;
    rep (i, sz(ss)) rep (j, sz(tt)) {
      if (ss[i] <= x && tt[j] <= x) ans = min(ans, max(x - ss[i], x - tt[j]));
      else if (x <= ss[i] && x <= tt[j]) ans = min(ans, max(ss[i] - x, tt[j] - x));
      else ans = min(ans, min(2 * abs(ss[i] - x) + abs(tt[j] - x), abs(ss[i] - x) + 2 * abs(tt[j] - x)));
    }

    cout << ans << endl;
  }
}
