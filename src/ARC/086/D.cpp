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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll maxv = a[0], minv = a[0];
  int maxIdx = 0, minIdx = 0;
  rep(i, n) {
    if (maxv < a[i]) {
      maxv = a[i];
      maxIdx = i;
    }
    if (minv > a[i]) {
      minv = a[i];
      minIdx = i;
    }
  }

  vector<pii> ans;
  if (abs(maxv) > abs(minv)) {
    rep(i, n) {
      if (a[i] < 0) {
        ans.eb(mp(maxIdx, i));
      }
    }
    rep(i, n - 1) ans.eb(mp(i, i + 1));
  } else {
    rep(i, n) {
      if (a[i] > 0) {
        ans.eb(mp(minIdx, i));
      }
    }
    for (int i = n - 1; i > 0; i--) ans.eb(mp(i, i - 1));
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i].F + 1 << ' ' << ans[i].S + 1 << endl;
}
